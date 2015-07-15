/* Node.h -- ��������ڵ��ͷ�ļ� */
#ifndef NODE_H_
#define NODE_H_
#include <stdbool.h>

/* �ض��ڳ�������� */
struct originalSet
{
	//�û��Զ������������
	int TestNum;
};

/* ������           */
typedef struct originalSet Data;

/* �ڵ�ģ��         */
typedef struct node
{
	Data data;
	struct node * next;	//ָ����
}Node;

/* ͷ�ڵ�ָ��       */
typedef Node * Head;

/* �ӿں���ԭ��     */

/* ����:����ָ��next,����Data�Ľڵ� */
/* ����ǰ: next ָ����һ���ڵ�,Data */
/* Ϊ�ڵ�������                     */
/* ������: ��������ɹ�,�򷵻�ָ��  */
/* �����ڵ��ָ��,���򷵻ؿ�ָ��    */
Node * CreateNode(Data av_data, Node * av_next);

/* ����:�Ƚ������ڵ��Ƿ����        */
/* ����ǰ: p_node, p_node1�ֱ�ΪҪ  */
/* ���бȽϵ������ڵ��ָ��         */
/* ������: �������ָ����ȷ�����   */
/* ���򷵻ؼ�                       */
bool Equals_Node(const Data elem, const Node * av_node1);

#endif
