/* Node.cpp -- ʵ��Node�ӿ� */
#include <stdio.h>
#include <stdlib.h>

#include "Node.h"
//�ڲ�����,��ָ��ڵ��p_node��������ֵdata
static void CopyDataToNode(Node * av_node, Data av_data);

//�ӿں���ʵ��
Node * CreateNode(Data av_data, Node * av_next)
{
	Node * res;
	res = (Node *)malloc(sizeof(Node));

	if (NULL == res){
		return NULL;
	}else{
		CopyDataToNode(res, av_data);
		res->next = av_next;
		return res;
	}
}

bool Equals_Node(const Data elem, const Node * av_node1)
{
	return elem.TestNum == av_node1->data.TestNum ? true : false;
}

//�ڲ�����ʵ��
static void CopyDataToNode(Node * av_node, Data av_data)
{
	av_node->data = av_data;		//������Ϊ����ͬ�Ľṹ����ֱ�Ӹ�ֵ
}
