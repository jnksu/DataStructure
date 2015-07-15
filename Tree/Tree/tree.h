//tree.h -- ����������		
//���в���������ͬ����Ŀ	
#ifndef _TREE_H_
#define _TREE_H_

#define STRLEN 20		//����ַ�������
#define MAXITEMS 10     //���������������
#define MAXARRLEN 30	//˳�����󳤶�

#include <stdbool.h>

//���԰�Item���¶���Ϊ���ʵ�����
typedef struct item
{
	char petName[STRLEN];
	char petKind[STRLEN];
	char ArrPetKind[MAXARRLEN][STRLEN];					//���ö�΢����洢��������
	int ListLen;										//��¼˳�����Ԫ�صĸ���
}Item;

//������������
typedef struct node
{
	Item item;
	struct node * left_node;
	struct node * right_node;
}Node;

typedef struct tree
{
	Node * root;				//ָ�������ָ��
	unsigned int size;			//������Ŀ�ĸ���	
}Tree;

//����ԭ�� 
//����:��һ������ʼ��Ϊ����
//����ǰ:ptreeָ��һ����
//������:�����ѱ���ʼ��Ϊ����
void InitializeTree(Tree * ptree);

//����:ȷ�����Ƿ�Ϊ����
//����ǰ:ptreeָ��һ����
//������:�����Ϊ��������true;���򷵻�false
bool TreeIsEmpty(const Tree * ptree);

//����:ȷ�����Ƿ�����
//����ǰ:ptreeָ��һ����
//������:����������򷵻�true;���򷵻�false
bool TreeIsFull(const Tree * ptree);

//����:ȷ��������Ŀ�ĸ���
//����ǰ:ptreeָ��һ����
//������:��������������Ŀ�ĸ���
unsigned int TreeItemCount(const Tree * ptree);

//����:���������һ����Ŀ***
//����ǰ:pi�Ǵ���ӵ���Ŀ�ĵ�ַ
//      ptreeָ��һ���Ѿ���ʼ������
//������:�������,�����Ѹ���Ŀ
//		��ӵ����в�����true
//		����������false
bool AddItem(const Item * pi, Tree * ptree);

//����:�����в���һ����Ŀ 
//����ǰ:piָ��һ����Ŀ
//		 ptreeָ��һ���Ѿ���ʼ������
//������:����ڸ����д�����Ӧ��Ŀ,��������true
//		 ���򷵻�false
bool Intree(const Item * pi, const Tree * ptree);

//����:������ɾ��һ����Ŀ
//����ǰ:pi�Ǵ�ɾ������Ŀ�ĵ�ַ
//		 ptreeָ��һ���Ѿ���ʼ������
//������:�������,����������ɾ������Ŀ
//		 ������true,����������false
bool DeleteItem(const Item * pi, Tree * ptree);

//����:������������Ӧ����Ŀ
//����ǰ:piָ��һ����Ŀ,
//		 ptreeָ��һ���Ѿ���ʼ������
//������:��������д��ڸ���Ŀ,����������Ӧ��Ŀ��ָ��
//		���򷵻�NULL
const Item * seekInTree(const Tree * ptree, Item * pi);

//����:��һ���������������е�ÿһ����Ŀ
//����ǰ:ptreeָ��һ����
//		 pfunָ��һ��û�з���ֵ�ĺ���
//		 �ú�������һ��Item��Ϊ����
//������:pfunָ��ĺ�����������
//		���е�ÿ����Ŀһ��
void Traverse(const Tree * ptree, void (* pfun)(Item item));

//����:������ɾ�����
//����ǰ:ptreeָ��һ���Ѿ���ʼ������
//������:����Ϊ��
void DeleteAll(Tree * ptree);
#endif 
