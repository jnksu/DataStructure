/* LoopQueue.cpp --ʵ��ѭ�����нӿ� */
/* ��0��ʼ,�Ȳ����ټ�1 head == tail */
/* ���п�, tail + 1 % size == head  */
/* ������                           */

#include "LoopQueue.h"
#include <stdlib.h>
#include <stdio.h>
#define NUMOFLOOPQUEUE 1
#define BUFFEROFLOOPQUEUE 64
#define QUEUELEN	10
/* �ڲ����� */
static void CopyOfData(Data data, Data * pos);

LoopQueue * createLoopQueue(unsigned int len)
{
	//���ö�������������Сֵ
	if (len < BUFFEROFLOOPQUEUE)
		len = BUFFEROFLOOPQUEUE;
	LoopQueue * produce = (LoopQueue *)calloc(NUMOFLOOPQUEUE, sizeof(LoopQueue));
	if (NULL == produce)
		return NULL;	//����ڴ����ʧ��
	//��ʼ������
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
	//���������Զ��н�������
	if ((av_queue->Wadd + 1) % av_queue->queue_size
		== av_queue->Adelete){
		
		int count = 0;
		Data * temp = (Data *)calloc(av_queue->queue_size * 2,sizeof(Data));	//�µ�����
		unsigned int flag = av_queue->Adelete;

		while (flag != av_queue->Wadd){
			*(temp + count++) = *(av_queue->queue + flag);
			flag = (flag + 1) % av_queue->queue_size;
		}
		//����ԭ��������
		free(av_queue->queue);
		//����ָ��
		av_queue->queue = temp;
		//�����α�
		av_queue->Adelete = 0;
		av_queue->Wadd = count;
		//���������С
		av_queue->queue_size *= 2;
	}

	//���Ԫ��
	CopyOfData(elem, (av_queue->queue + av_queue->Wadd));
	av_queue->Wadd = (av_queue->Wadd + 1) % av_queue->queue_size;

	return true;
}

Data * DeLoopQueue(LoopQueue * av_queue)
{
	//�������Ϊ��
	if (av_queue->Adelete == av_queue->Wadd)
		return NULL;
	//����Ҫɾ����Ԫ��s
	Data * del = av_queue->queue + av_queue->Adelete;

	av_queue->Adelete = (av_queue->Adelete + 1) % av_queue->queue_size;
	//���ر����ָ��
	return del;
}

void reserveLoopQueue(LoopQueue * av_queue)
{
	//����һ����ʱ����
	Data * arr = (Data *)calloc(av_queue->queue_size, sizeof(Data));
	int count = 0;
	//������Ԫ�س��ӵ�ѭ��������
	for (; av_queue->Adelete != av_queue->Wadd; count++){
		*(arr + count) = *(DeLoopQueue(av_queue));
	}
	//������Ԫ��������ӵ�ѭ��������
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
