/* LinkQueue.cpp --ʵ����ʽ���нӿ� */
#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

/* �ڲ����� */
static void CopyOfData(Data data, LinkQueueNode * pos);

Head * createLinkQueue(void)
{
	//����һ��ָ��������ݽṹ��ָ��
	Head *  head = (Head *)calloc(1, sizeof(Head));
	//��ʼ��ָ��
	head->head = head->tail = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));

	return head;
}

bool LinkQueueIsEmpty(const Head * av_queue)
{
	//���ͷָ�����βָ��,������Ϊ��
	return av_queue->head == av_queue->tail ? true : false;
}

unsigned int countLinkQueue(const Head * av_queue)
{
	LinkQueueNode * rear = av_queue->head;
	int count = 0;

	while (rear != av_queue->tail){
		count++;
		rear = rear->next;
	}

	return count;
}

bool EnLinkQueue(Head * av_queue, Data elem)
{
	//��βָ�����һ���µĽ��,ʹ��βָ������ִ���µĽ��
	LinkQueueNode * node = (LinkQueueNode *)calloc(1, sizeof(LinkQueueNode));

	if (NULL == node)
		return false;
	CopyOfData(elem, av_queue->tail);
	//���ڸ�βָ�������ָ��
	av_queue->tail->next = node;
	//βָ���ƶ�����ָ��
	av_queue->tail = av_queue->tail->next;
	return true;
}

LinkQueueNode * DeLinkQueue(Head * av_queue)
{
	//�ж������Ƿ�Ϊ��
	if (av_queue->head == av_queue->tail)
		return NULL;
	//���浱ǰ��Ҫɾ���Ľ���ָ��
	LinkQueueNode * temp = av_queue->head;
	//ɾ����ǰͷ���
	av_queue->head = av_queue->head->next;
	//�����Ѿ�ɾ����ָ��(ע���ͷ�!��ֹ�ڴ�й©!)
	return temp;
}

void toStringLinkQueue(const Head * av_queue)
{
	putchar('[');
	LinkQueueNode * rear = av_queue->head;
	//��������
	while (rear != av_queue->tail){
		printf("%d ", rear->elem);
		rear = rear->next;
		if (rear != av_queue->tail)
			printf(",");
	}
	putchar(']');
	putchar('\n');
}

void reserveLinkQueue(Head * av_queue)
{
	LinkQueueNode * prev;	//ǰ����� 
	LinkQueueNode * rear;	//��ǰ���
	LinkQueueNode * tail;   //��̽��
	//ǰ��,��̽��ָ��Ϊ��,��ǰ���Ϊͷ���
	prev = NULL;
	tail = NULL;
	rear = av_queue->head;
	//����ǰ��㲻����β�ս��ʱ 
	while (rear != av_queue->tail){
		tail = rear->next;		//β��㸳ֵ
		rear->next = prev;		//��ת
		prev = rear;			//ǰ����㸳ֵ
		rear = tail;			//��ǰ����ƶ�
	}
	free(av_queue->tail);//�������ս��
	//��ͷ������ӿս��ʹ���Ϊβ���
	av_queue->head->next = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	//β��㸳ֵ
	av_queue->tail = av_queue->head->next;
	//ͷ��㸳ֵ
	av_queue->head = prev;
}

void destroyLinkQueue(Head * av_queue)
{
	LinkQueueNode * temp;	//����Ҫ���ٽ�����һ�����

	while (av_queue->head != av_queue->tail){
		temp = av_queue->head->next;
		free(av_queue->head);
		av_queue->head = temp;
	}
	//����β���
	free(av_queue->tail);
	//���ٶ��н��
	free(av_queue);
}

static void CopyOfData(Data data, LinkQueueNode * pos)
{
	pos->elem = data;
}