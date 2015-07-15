/* LinkList.cpp -- ʵ����ͷ���,������ӿ� */
#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"

/* �ӿں���ʵ�� */
Head CreateNullLinkList(void)
{
	Head list = NULL;
	return list;
}

Node * CreateNullLinkList(Data * element, int size)
{
	// ����ͷ���
	Head head = CreateNode(*element, NULL);
	//�����α�Ľ��ָ��
	Node * rear = head;

	for (int index = 1; index < size; index++){
		rear->next = CreateNode(*(element + index), NULL);
		//�ڵ��Ƿ񴴽��ɹ�
		if (NULL == rear->next){
			destroylinkList(&head);	//���ٴ���ʧ�ܵ�����
			fprintf(stderr, "The LinkList Create Failure!\n");
			exit(EXIT_FAILURE);
		}
		rear = rear->next;
	}

	return head;
}

Head  CopyOfLinkList(const Head * list)
{
	//����ͷ���
	Head head = CreateNode((*list)->data, NULL);
	//����Ҫ����������α�
	Node * rear_copy = (*list)->next;
	//���ڴ���ֵ������α�
	Node * rear_local = head;

	while (NULL != rear_copy){
		rear_local->next = CreateNode(rear_copy->data,NULL);
		//����Ƿ񴴽��ɹ�
		if (NULL == rear_local->next){
			destroylinkList(&head); //���ٴ���ʧ�ܵ�����
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
	
	//�Ϸ��Լ��
	if (pos <= 0)
		return NULL;
	while (NULL != rear){
		ver++;
		if (pos == ver){
			return rear;
		}
		rear = rear->next;
	}
	//���δ�ҵ�,���ؿ�ָ��
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

	//ͷ����
	if (pos <= 1){
		*list = CreateNode(elem, res);
	}
	else{
		//β����
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
		//ɾ��ͷָ��
		*list = (*list)->next;
	}else{
		for (int index = 1; index < pos - 1
			&& NULL != rear->next; index++){
			rear = rear->next;
		}
		deleteNode = rear->next;
		//�����Ҫɾ���Ľ�㲻Ϊ��
		if (NULL != rear->next)
			rear->next = rear->next->next;
	}
	
	return deleteNode;
}

void RemoveAllNode_LinkList(Head * list)
{
	destroylinkList(list);
	*list = NULL;	//����ͷָ��Ϊ��
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
		//������������Ⱥ�, ��������бȽ�
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

	//���Ϊͷ����򷵻�NULL
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
	//��ʼ��ʱǰ���ͺ�̽��Ϊ��
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
	Node * rear;	//����Ҫ�ͷŽ�����һ�����

	while ((*list) != NULL){
		rear = (*list)->next;		/* ������һ�����ĵ�ַ */
		free((*list));				/* �ͷŵ�ǰ���         */
		(*list) = rear;				/* ǰ������һ�����     */
	}
}
