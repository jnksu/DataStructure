/* LinkQueue.cpp --实现链式队列接口 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkQueue.h"

/* 内部函数 */
static void CopyOfData(Data data, LinkQueueNode * pos);

Head * createLinkQueue(void)
{
	//创建一个指向队列数据结构的指针
	Head *  head = (Head *)calloc(1, sizeof(Head));
	//初始两指针
	head->head = head->tail = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));

	return head;
}

bool LinkQueueIsEmpty(const Head * av_queue)
{
	//如果头指针等于尾指针,则链表为空
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
	//给尾指针分配一个新的结点,使得尾指针总是执行新的结点
	LinkQueueNode * node = (LinkQueueNode *)calloc(1, sizeof(LinkQueueNode));

	if (NULL == node)
		return false;
	CopyOfData(elem, av_queue->tail);
	//现在给尾指针分配新指针
	av_queue->tail->next = node;
	//尾指针移动到新指针
	av_queue->tail = av_queue->tail->next;
	return true;
}

LinkQueueNode * DeLinkQueue(Head * av_queue)
{
	//判断链表是否为空
	if (av_queue->head == av_queue->tail)
		return NULL;
	//保存当前将要删除的结点的指针
	LinkQueueNode * temp = av_queue->head;
	//删除当前头结点
	av_queue->head = av_queue->head->next;
	//返回已经删除的指针(注意释放!防止内存泄漏!)
	return temp;
}

void toStringLinkQueue(const Head * av_queue)
{
	putchar('[');
	LinkQueueNode * rear = av_queue->head;
	//遍历队列
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
	LinkQueueNode * prev;	//前驱结点 
	LinkQueueNode * rear;	//当前结点
	LinkQueueNode * tail;   //后继结点
	//前驱,后继结点指针为空,当前结点为头结点
	prev = NULL;
	tail = NULL;
	rear = av_queue->head;
	//当当前结点不等于尾空结点时 
	while (rear != av_queue->tail){
		tail = rear->next;		//尾结点赋值
		rear->next = prev;		//反转
		prev = rear;			//前驱结点赋值
		rear = tail;			//当前结点移动
	}
	free(av_queue->tail);//除掉最后空结点
	//给头结点增加空结点使其称为尾结点
	av_queue->head->next = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	//尾结点赋值
	av_queue->tail = av_queue->head->next;
	//头结点赋值
	av_queue->head = prev;
}

void destroyLinkQueue(Head * av_queue)
{
	LinkQueueNode * temp;	//保存要销毁结点的下一个结点

	while (av_queue->head != av_queue->tail){
		temp = av_queue->head->next;
		free(av_queue->head);
		av_queue->head = temp;
	}
	//销毁尾结点
	free(av_queue->tail);
	//销毁队列结点
	free(av_queue);
}

static void CopyOfData(Data data, LinkQueueNode * pos)
{
	pos->elem = data;
}