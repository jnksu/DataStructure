/* Node.cpp -- 实现Node接口 */
#include <stdio.h>
#include <stdlib.h>

#include "Node.h"
//内部函数,对指向节点的p_node的数据域赋值data
static void CopyDataToNode(Node * av_node, Data av_data);

//接口函数实现
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

//内部函数实现
static void CopyDataToNode(Node * av_node, Data av_data)
{
	av_node->data = av_data;		//这里因为是相同的结构所以直接赋值
}
