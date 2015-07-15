/* LoopQueue.cpp --实现循环队列接口 */
/* 从0开始,先操作再加1 head == tail */
/* 队列空, tail + 1 % size == head  */
/* 队列满                           */

#include "LoopQueue.h"
#include <stdlib.h>
#include <stdio.h>
#define NUMOFLOOPQUEUE 1
#define BUFFEROFLOOPQUEUE 64
#define QUEUELEN	10
/* 内部函数 */
static void CopyOfData(Data data, Data * pos);

LoopQueue * createLoopQueue(unsigned int len)
{
	//设置队列数组容量最小值
	if (len < BUFFEROFLOOPQUEUE)
		len = BUFFEROFLOOPQUEUE;
	LoopQueue * produce = (LoopQueue *)calloc(NUMOFLOOPQUEUE, sizeof(LoopQueue));
	if (NULL == produce)
		return NULL;	//如果内存分配失败
	//初始化队列
	produce->Adelete = 0;
	produce->Wadd = 0;
	produce->queue = (Data *)calloc(len, sizeof(Data));
	produce->queue_size = len;

	return produce;
}

bool LoopQueueIsEmpty(const LoopQueue * av_queue)
{
	return av_queue->Adelete == av_queue->Wadd ? true : false;
}

unsigned int countLoopQueue(const LoopQueue * av_queue)
{
	if (NULL == av_queue){
		fprintf(stderr, "Illegal argument\n");
		exit(EXIT_FAILURE);
	}
	unsigned int count = 0;
	unsigned int flag = av_queue->Adelete;

	while (flag != av_queue->Wadd){
		count++;
		flag = (flag + 1) % av_queue->queue_size;
	}

	return count;
}

bool EnLoopQueue(LoopQueue * av_queue, Data elem)
{
	if (NULL == av_queue)
		return false;
	//队列已满对队列进行扩容
	if ((av_queue->Wadd + 1) % av_queue->queue_size
		== av_queue->Adelete){
		
		int count = 0;
		Data * temp = (Data *)calloc(av_queue->queue_size * 2,sizeof(Data));	//新的数组
		unsigned int flag = av_queue->Adelete;

		while (flag != av_queue->Wadd){
			*(temp + count++) = *(av_queue->queue + flag);
			flag = (flag + 1) % av_queue->queue_size;
		}
		//销毁原来的数组
		free(av_queue->queue);
		//更改指针
		av_queue->queue = temp;
		//设置游标
		av_queue->Adelete = 0;
		av_queue->Wadd = count;
		//设置数组大小
		av_queue->queue_size *= 2;
	}

	//入队元素
	CopyOfData(elem, (av_queue->queue + av_queue->Wadd));
	av_queue->Wadd = (av_queue->Wadd + 1) % av_queue->queue_size;

	return true;
}

Data * DeLoopQueue(LoopQueue * av_queue)
{
	//如果队列为空
	if (av_queue->Adelete == av_queue->Wadd)
		return NULL;
	//保存要删除的元素s
	Data * del = av_queue->queue + av_queue->Adelete;

	av_queue->Adelete = (av_queue->Adelete + 1) % av_queue->queue_size;
	//返回保存的指针
	return del;
}

void reserveLoopQueue(LoopQueue * av_queue)
{
	//创建一个临时数组
	Data * arr = (Data *)calloc(av_queue->queue_size, sizeof(Data));
	int count = 0;
	//将队列元素出队到循环队列中
	for (; av_queue->Adelete != av_queue->Wadd; count++){
		*(arr + count) = *(DeLoopQueue(av_queue));
	}
	//将数组元素逆序入队到循环队列中
	while (--count >= 0){
		EnLoopQueue(av_queue, arr[count]);
	}

	free(arr);
}

void toStringLoopQueue(const LoopQueue * av_queue)
{
	if (NULL == av_queue)
		return;
	putchar('[');

	unsigned int flag = av_queue->Adelete;

	while (flag != av_queue->Wadd){
		printf("%d", *(av_queue->queue + flag));
		flag = (flag + 1) % av_queue->queue_size;
		if (flag != av_queue->Wadd)
			putchar(',');
	}
	printf("]\n");
}

void destroyLoopQueue(LoopQueue * av_queue)
{
	free(av_queue->queue);
	free(av_queue);
}

bool LoopQueueIsFull(const LoopQueue * av_queue)
{
	return countLoopQueue(av_queue) == QUEUELEN ? true : false;
}

static void CopyOfData(Data data, Data * pos)
{
	*pos = data;
}
