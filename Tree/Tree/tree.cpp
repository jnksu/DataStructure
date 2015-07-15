//��ȥ������Ϣ
#define _CRT_SECURE_NO_WARNINGS 1
//tree.c -- �����͵�֧�ֺ���
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ֲ���������
typedef struct pair
{
	Node * parent;
	Node * child;
}Pair;

//�ֲ�����ԭ��
static Node * makeNode(const Item * pi);
static void addNode(Node * new_Node, Node * root);
static bool toLeft(const Item * pi, const Item * pi1);
static bool toRight(const Item * pi, const Item * pi1);
static Pair seekItem(const Item * pi, const Tree * ptree);
static void deleteNode(Node ** ptr);
static void inOrder(const Node * root, void (* fun)(Item item));
static void deleteAllNode(Node * root);

//��������
void InitializeTree(Tree * ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree * ptree)
{
	return (NULL == ptree->root) ? true : false;
}

bool TreeIsFull(const Tree * ptree)
{
	return (MAXITEMS == ptree->size) ? true : false;
}

unsigned int TreeItemCount(const Tree * ptree)
{
	return ptree->size;
}

bool AddItem(const Item * pi, Tree * ptree)
{
	Node * new_node;
	Pair seek;

	if (TreeIsFull(ptree))
	{
		fprintf(stderr,"Tree is full.\n");
		return false;						//�����Ľ��������ʱ����ǰ����
	}
	if ((seek = seekItem(pi, ptree)).child != NULL)
	{
		if (seek.child->item.ListLen < MAXARRLEN)
			strcpy(seek.child->item.ArrPetKind[seek.child->item.ListLen], pi->petKind);		//���������ͬ����Ŀ,�򽫳������͸��Ƶ���Ӧ�Ľ����ȥ
		seek.child->item.ListLen++;
		return false;
	}
	new_node = makeNode(pi);				
	if (NULL == new_node)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;						//����½�㴴��ʧ����ǰ����
	}
	//�ɹ�������һ���½��
	ptree->size++;
	if (NULL == ptree->root)
	{
		ptree->root = new_node;				//���1:��Ϊ����,�½��Ϊ���ĸ����
	}
	else
	{
		addNode(new_node, ptree->root);		//���2:���ǿ�,���½����ӵ�����
	}
	return true;							//�ɹ�����
}

bool Intree(const Item * pi, const Tree * ptree)
{
	return (NULL == seekItem(pi, ptree).child) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;
	look = seekItem(pi, ptree);
	if (NULL == look.child)					 //�������в����ڴ���Ŀ�Ľ��
	{
		return false;
	}

	if (NULL == look.parent)				 //ɾ������Ŀ
	{		
		deleteNode(&ptree->root);
	}
	else if (look.parent->left_node == look.child)			//ɾ����ĿΪ��������ӽ��
	{
		deleteNode(&look.parent->left_node);
	}
	else
	{														//ɾ����ĿΪ��������ӽ��
		deleteNode(&look.parent->right_node);
	}
	ptree->size--;
	return true;
}

const Item * seekInTree(const Tree * ptree, Item * pi)
{
	Pair seek;
	seek = seekItem(pi, ptree);

	if (NULL == seek.child)
	{
		return NULL;
	}
	else
	{
		return &(seek.child->item);
	}
}

void Traverse(const Tree * ptree, void(*pfun)(Item item))
{
	if (ptree != NULL)
		inOrder(ptree->root, pfun);
}

void DeleteAll(Tree * ptree)
{
	if (ptree != NULL)
	{
		deleteAllNode(ptree->root);
		ptree->root = NULL;
		ptree->size = 0;
	}
}

//�ֲ�����
static Node * makeNode(const Item * pi)
{
	Node * new_node;

	new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		strcpy(new_node->item.petName, pi->petName);
		strcpy(new_node->item.ArrPetKind[0], pi->petKind);
		new_node->item.ListLen = 1;				//��ʼ��������
		new_node->left_node = NULL;
		new_node->right_node = NULL;
	}
	return new_node;
}

static void addNode(Node * new_node, Node * root)
{
	if (toLeft(&new_node->item, &root->item))
	{
		if (NULL == root->left_node)		//��������
		{
			root->left_node = new_node;		//��ӵ�������
		}
		else
		{
			addNode(new_node, root->left_node);
		}
	}
	else if (toRight(&new_node->item, &root->item))
	{
		if (NULL == root->right_node)		//��������
		{
			root->right_node = new_node;	//��ӵ�������
		}
		else
		{
			addNode(new_node, root->right_node);
		}
	}
	else
	{
		//��Ӧ������ͬ����Ŀ
		fprintf(stderr, "location error in addNode()\n");
		exit(EXIT_FAILURE);
	}
}

static bool toLeft(const Item * pi, const Item * pi1)
{
	int compl;
	
	if ((compl = strcmp(pi->petName, pi1->petName)) < 0)
	{
		return true;
	}
	else
	{
		return false;										//����������,�������������
	}
}

static bool toRight(const Item * pi, const Item * pi1)
{
	int compl;

	if ((compl = strcmp(pi->petName, pi1->petName)) > 0)
	{
		return true;
	}
	else
	{
		return false;										//����������,�������������
	}
}

static Pair seekItem(const Item * pi, const Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;								//��ʼ����ʱ��Ӹ���㿪ʼ

	if (NULL == look.child)
	{
		return look;										//��ǰ����
	}

	while (look.child != NULL)
	{
		if (toLeft(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left_node;
		}
		else if (toRight(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right_node;
		}
		else
		{
			break;											//look.child��Ŀ����Ŀ���ĵ�ַ
		}
	}
	return look;											//�ɹ�����
}

static void deleteNode(Node ** ptr)
{
	Node * temp;

	fputs((*ptr)->item.petName, stdout);
	if (NULL == (*ptr)->left_node)							//������Ϊ��
	{
		temp = *ptr;
		*ptr = (*ptr)->right_node;
		free(temp);
	}
	else if (NULL == (*ptr)->right_node)					//������Ϊ��
	{
		temp = *ptr;
		*ptr = (*ptr)->left_node;
		free(temp);
	}
	else													//��,����������Ϊ��
	{
		//�ҵ�������������λ��
		for (temp = (*ptr)->left_node; temp->right_node != NULL; temp = temp->right_node)
			continue;
		temp->right_node = (*ptr)->right_node;

		temp = *ptr;
		*ptr = (*ptr)->right_node;
		free(temp);
	}
}

static void inOrder(const Node * root, void(* pfun)(Item item))
{
	if (root != NULL)
	{
		inOrder(root->left_node, pfun);
		(*pfun)(root->item);
		inOrder(root->right_node, pfun);
	}
}

static void deleteAllNode(Node * root)
{
	Node * pringht;
	
	if (root != NULL)
	{
		pringht = root->right_node;
		deleteAllNode(root->left_node);
		//���ͷŴ洢�������͵ĵ�����

		free(root);
		deleteAllNode(pringht);
	}
}
