/* mall.c -- ʹ��Queue�ӿ� */
/* ��queue.cһ�����       */
#include "ldbg.h"			//debug
#include <stdio.h>
#include <stdlib.h>			/* Ϊrand()��srand()�ṩԭ�� */
#include <time.h>			/* Ϊtime()�����ṩԭ��      */
#include "LoopQueue.h"		/* �ı�Item��typedef         */	
#define MIN_PER_HR 60.0

bool new_customer(double);				/* ���¹˿͵�����? */
Data customer_time(long when);			/* ���ù˿Ͳ���    */

int main(int argc, char ** argv)
{
	LoopQueue * line;					/* ģ�����						*/
	Data temp;							/* �����¹˿͵�����   		  	*/
	int hours;							/* ģ���Сʱ��       		  	*/
	int per_hour;						/* ÿСʱ�˿͵�ƽ����  		  	*/
	long cycle, cycle_limit;			/* ѭ��������, ���������Ͻ�   	*/
	long turn_aways = 0;				/* ��������������ܾ��Ĺ˿��� 	*/
	long customer = 0;					/* ��������еĹ˿���		  	*/
	long served = 0;					/* ��ģ���ڼ�õ�����Ĺ˿��� 	*/
	long sum_line = 0;					/* �ۼƵĶ��г���			    */
	int wait_time = 0;					/* �ӵ�ǰ��Sigmund���������ʱ��*/
	double min_per_cust;				/* �˿͵�����ƽ�����ʱ��		*/
	long line_wait = 0;					/* �����ۼƵȴ�ʱ��				*/

	line = createLoopQueue(10);			
	srand(time(0));						/* �����ʼ��rand()����         */
	//����ģ���Сʱ��
	fputs("Case Study: Sigmund Lander's Advice Booth\n", stdout);
	fputs("Enter the number of simulation hours:\n", stdout);
	scanf_s("%d", &hours);
	cycle_limit = MIN_PER_HR * hours;
	//ÿ�˿͵���ʱ��
	fputs("Enter the average number of customers per hour: \n", stdout);
	scanf_s("%d", &per_hour);
	min_per_cust = MIN_PER_HR / per_hour;
	//�Զ��н��д���
	for (cycle = 0; cycle < cycle_limit; cycle++)
	{
		//�����1�������й˿͵���
		if (new_customer(min_per_cust)){
			if (LoopQueueIsFull(line)){
				turn_aways++;					//�˿ͱ��ܾ�
			}
			else{
				customer++;						//������е�����
				temp = customer_time(cycle);
				EnLoopQueue(line, temp);		//�˿����
			}
		}
		//�����ʱ�����޵ȴ�
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

/* ���֮�������ͽ����ϵ�ȥ����! */
bool new_customer(double para)
{
	//�����ɵĹ˿͵���ʱ��С��һ����ʱ,������Ϊ�¹˿Ͳ���
	if (rand() * para / RAND_MAX < 1)
		return true;
	else
		return false;
}

/* when �ǹ˿͵�����ʱ��                                 			*/
/* �������ص�һ��Item�ṹ,�ýṹ�Ĺ˿͵���ʱ������Ϊwhen 			*/
/* ��Ҫ��ѯ��ʱ������Ϊһ����Χ��1��3֮������ֵ                   */
Data customer_time(long when)
{
	Data cust;

	cust.process_time = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}
