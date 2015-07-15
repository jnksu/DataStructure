/* mall.c -- 使用Queue接口 */
/* 与queue.c一起编译       */
#include "ldbg.h"			//debug
#include <stdio.h>
#include <stdlib.h>			/* 为rand()和srand()提供原型 */
#include <time.h>			/* 为time()函数提供原型      */
#include "LoopQueue.h"		/* 改变Item的typedef         */	
#define MIN_PER_HR 60.0

bool new_customer(double);				/* 有新顾客到来吗? */
Data customer_time(long when);			/* 设置顾客参量    */

int main(int argc, char ** argv)
{
	LoopQueue * line;					/* 模拟队列						*/
	Data temp;							/* 关于新顾客的数据   		  	*/
	int hours;							/* 模拟的小时数       		  	*/
	int per_hour;						/* 每小时顾客的平均数  		  	*/
	long cycle, cycle_limit;			/* 循环计数器, 计数器的上界   	*/
	long turn_aways = 0;				/* 因队列已满而被拒绝的顾客数 	*/
	long customer = 0;					/* 被加入队列的顾客数		  	*/
	long served = 0;					/* 在模拟期间得到服务的顾客数 	*/
	long sum_line = 0;					/* 累计的队列长度			    */
	int wait_time = 0;					/* 从当前到Sigmund空闲所需的时间*/
	double min_per_cust;				/* 顾客到来的平均间隔时间		*/
	long line_wait = 0;					/* 队列累计等待时间				*/

	line = createLoopQueue(10);			
	srand(time(0));						/* 随机初始化rand()函数         */
	//输入模拟的小时数
	fputs("Case Study: Sigmund Lander's Advice Booth\n", stdout);
	fputs("Enter the number of simulation hours:\n", stdout);
	scanf_s("%d", &hours);
	cycle_limit = MIN_PER_HR * hours;
	//每顾客到达时间
	fputs("Enter the average number of customers per hour: \n", stdout);
	scanf_s("%d", &per_hour);
	min_per_cust = MIN_PER_HR / per_hour;
	//对队列进行处理
	for (cycle = 0; cycle < cycle_limit; cycle++)
	{
		//如果这1分钟内有顾客到来
		if (new_customer(min_per_cust)){
			if (LoopQueueIsFull(line)){
				turn_aways++;					//顾客被拒绝
			}
			else{
				customer++;						//进入队列的人数
				temp = customer_time(cycle);
				EnLoopQueue(line, temp);		//顾客入队
			}
		}
		//如果此时队列无等待
		if (wait_time <= 0 && !LoopQueueIsEmpty(line))
		{
			Data * de = DeLoopQueue(line);
			wait_time = de->process_time;
			line_wait += cycle - de->arrive;
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += countLoopQueue(line);
	}

	if (customer > 0){
		printf("customers accepted: %ld\n", customer);
		printf("  customers served: %ld\n", served);
		printf("         turnaways: %ld\n", turn_aways);
		printf("average queue size: %.2f\n",
				(double)sum_line / cycle_limit);
		printf(" average wait time: %.2f minutes\n",
				(double)line_wait / served);
	}else{
		fputs("No customers\n", stdout);
	}

	destroyLoopQueue(line);
	fputs("Bye!\n", stdout);
	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
} 

/* 随机之类的事情就交给上帝去做吧! */
bool new_customer(double para)
{
	//当生成的顾客到达时间小于一分钟时,即可认为新顾客产生
	if (rand() * para / RAND_MAX < 1)
		return true;
	else
		return false;
}

/* when 是顾客到来的时间                                 			*/
/* 函数返回的一个Item结构,该结构的顾客到来时间设置为when 			*/
/* 需要咨询的时间设置为一个范围在1到3之间的随机值                   */
Data customer_time(long when)
{
	Data cust;

	cust.process_time = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}
