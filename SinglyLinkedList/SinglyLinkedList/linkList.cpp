/* LinkList.cpp -- 实现无头结点,单链表接口 */
#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"

/* 接口函数实现 */
Head CreateNullLinkList(void)
{
	Head list = NULL;
	return list;
}

Node * CreateNullLinkList(Data * element, int size)
{
	// 创建头结点
	Head head = CreateNode(*element, NULL);
	//用于游标的结点指针
	Node * rear = head;

	for (int index = 1; index < size; index++){
		rear->next = CreateNode(*(element + index), NULL);
		//节点是否创建成功
		if (NULL == rear->next){
			destroylinkList(&head);	//销毁创建失败的链表
			fprintf(stderr, "The LinkList Create Failure!\n");
			exit(EXIT_FAILURE);
		}
		rear = rear->next;
	}

	return head;
}

Head  CopyOfLinkList(const Head * list)
{
	//创建头结点
	Head head = CreateNode((*list)->data, NULL);
	//用于要复制链表的游标
	Node * rear_copy = (*list)->next;
	//用于待赋值链表的游标
	Node * rear_local = head;

	while (NULL != rear_copy){
		rear_local->next = CreateNode(rear_copy->data,NULL);
		//结点是否创建成功
		if (NULL == rear_local->next){
			destroylinkList(&head); //销毁创建失败的链表
			fprintf(stderr, "The LinkList Create Failure!\n");
			exit(EXIT_FAILURE);
		}
		rear_local = rear_local->next;
		rear_copy = rear_copy->next;
	}

	return head;
}

bool LinkListIsEmpty(const Head * list)
{
	return NULL == (*list) ? true : false;
}

unsigned int Length_LinkList(const Head * list)
{
	unsigned int count = 0;

	Node * rear = (*list);

	while (NULL != rear){
		count++;
		rear = rear->next;
	}
	return count;
}

Node * GetData_LinkList(const Head * list, int pos)
{
	unsigned int ver = 0;
	Node * rear = *list;
	
	//合法性检查
	if (pos <= 0)
		return NULL;
	while (NULL != rear){
		ver++;
		if (pos == ver){
			return rear;
		}
		rear = rear->next;
	}
	//如果未找到,返回空指针
	return NULL;
}

bool SetData_LinkList(const Head * list, int pos, Data elem)
{
	Node * res = GetData_LinkList(list, pos);

	if (NULL == res)
		return false;
	else{
		res->data = elem;
		return true;
	}
}

void Insert_LinkList(Head * list, int pos, Data elem)
{
	Node * res = *list;
	Node * tail;

	//头插入
	if (pos <= 1){
		*list = CreateNode(elem, res);
	}
	else{
		//尾插入
		for (int index = 1; index < pos - 1 && res->next != NULL; index++){
			res = res->next;
		}

		tail = res->next;
		res->next = CreateNode(elem, tail);
	}
}

void AppendNode_LinkList(Head * list, Data elem)
{
	Insert_LinkList(list, APP_MAX, elem);
}

Node * RemovedNode_LinkList(Head * list, int pos)
{
	Node * rear = *list;
	Node * deleteNode;

	if (pos <= 0){
		return NULL;
	}else if (1 == pos){
		deleteNode = *list;
		//删除头指针
		*list = (*list)->next;
	}else{
		for (int index = 1; index < pos - 1
			&& NULL != rear->next; index++){
			rear = rear->next;
		}
		deleteNode = rear->next;
		//如果将要删除的结点不为空
		if (NULL != rear->next)
			rear->next = rear->next->next;
	}
	
	return deleteNode;
}

void RemoveAllNode_LinkList(Head * list)
{
	destroylinkList(list);
	*list = NULL;	//更改头指针为空
}

Node * SearchNode(const Head * list, Data key)
{
	Node * rear = *list;

	while (NULL != rear){
		if (Equals_Node(key, rear))
			return rear;
		rear = rear->next;
	}
	return NULL;
}

bool Equals_LinkList(const Head * av_list, const Head * av_list1)
{
	if (*av_list == *av_list1){
		return true;
	}
	else if(Length_LinkList(av_list) != Length_LinkList(av_list1)){
		return false;
	}else{
		Node * rear_list = *av_list;
		Node * rear_list1 = *av_list1;
		//两个链表长度相等后, 逐个结点进行比较
		while (rear_list != NULL){
			if (!Equals_Node(rear_list->data, rear_list1))
				return false;
			rear_list = rear_list->next;
			rear_list1 = rear_list1->next;
		}
		return true;
	}
}

Node * GetPioneer_LinkList(const Head * list, int pos)
{
	Node * rear = *list;

	//如果为头结点则返回NULL
	if (pos <= 1)
		return NULL;
	for (int index = 1; index < pos - 1 &&
		rear->next != NULL; index++){
		rear = rear->next;
	}
	
	return rear;
}

Node * GetSucceed_LinkList(const Head * list, int pos)
{
	Node * rear = *list;
	
	if (pos > 0){
		for (int index = 1; index < pos && rear != NULL; index++)
			rear = rear->next;
		if (NULL != rear)
			return rear->next;
	}

	return NULL;
}

void Reverse_LinkList(Head * list)
{
	Head prev, rear, tail;
	//初始化时前驱和后继结点为空
	prev = NULL;
	tail = NULL;
	rear = *list;

	while (rear != NULL){
		tail = rear->next;
		rear->next = prev;
		prev = rear;
		rear = tail;
	}

	*list = prev;
}

void toString_LinkList(const Head * av_list)
{
	Node * rear = *av_list;
	
	putchar('[');
	while (NULL != rear){
		printf("%d %p", rear->data, rear->next);
		
		if (NULL != rear->next)
			putchar(',');

		rear = rear->next;
	}
	putchar(']');
	putchar('\n');
}

void destroylinkList(Head * list)
{
	Node * rear;	//保留要释放结点的下一个结点

	while ((*list) != NULL){
		rear = (*list)->next;		/* 保存下一个结点的地址 */
		free((*list));				/* 释放当前结点         */
		(*list) = rear;				/* 前进到下一个结点     */
	}
}
