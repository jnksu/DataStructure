//除去报错信息
#define _CRT_SECURE_NO_WARNINGS 1
//tree.c -- 树类型的支持函数
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//局部数据类型
typedef struct pair
{
	Node * parent;
	Node * child;
}Pair;

//局部函数原型
static Node * makeNode(const Item * pi);
static void addNode(Node * new_Node, Node * root);
static bool toLeft(const Item * pi, const Item * pi1);
static bool toRight(const Item * pi, const Item * pi1);
static Pair seekItem(const Item * pi, const Tree * ptree);
static void deleteNode(Node ** ptr);
static void inOrder(const Node * root, void (* fun)(Item item));
static void deleteAllNode(Node * root);

//函数定义
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
		return false;						//当树的结点已满的时候提前返回
	}
	if ((seek = seekItem(pi, ptree)).child != NULL)
	{
		if (seek.child->item.ListLen < MAXARRLEN)
			strcpy(seek.child->item.ArrPetKind[seek.child->item.ListLen], pi->petKind);		//如果存在相同的项目,则将宠物类型复制到相应的结点中去
		seek.child->item.ListLen++;
		return false;
	}
	new_node = makeNode(pi);				
	if (NULL == new_node)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;						//如果新结点创建失败提前返回
	}
	//成功创建了一个新结点
	ptree->size++;
	if (NULL == ptree->root)
	{
		ptree->root = new_node;				//情况1:树为空树,新结点为树的根结点
	}
	else
	{
		addNode(new_node, ptree->root);		//情况2:树非空,把新结点添加到树中
	}
	return true;							//成功返回
}

bool Intree(const Item * pi, const Tree * ptree)
{
	return (NULL == seekItem(pi, ptree).child) ? false : true;
}

bool DeleteItem(const Item * pi, Tree * ptree)
{
	Pair look;
	look = seekItem(pi, ptree);
	if (NULL == look.child)					 //二叉树中不存在此项目的结点
	{
		return false;
	}

	if (NULL == look.parent)				 //删除根项目
	{		
		deleteNode(&ptree->root);
	}
	else if (look.parent->left_node == look.child)			//删除项目为父结点左子结点
	{
		deleteNode(&look.parent->left_node);
	}
	else
	{														//删除项目为父结点右子结点
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

//局部函数
static Node * makeNode(const Item * pi)
{
	Node * new_node;

	new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		strcpy(new_node->item.petName, pi->petName);
		strcpy(new_node->item.ArrPetKind[0], pi->petKind);
		new_node->item.ListLen = 1;				//初始化计数器
		new_node->left_node = NULL;
		new_node->right_node = NULL;
	}
	return new_node;
}

static void addNode(Node * new_node, Node * root)
{
	if (toLeft(&new_node->item, &root->item))
	{
		if (NULL == root->left_node)		//空左子树
		{
			root->left_node = new_node;		//添加到左子树
		}
		else
		{
			addNode(new_node, root->left_node);
		}
	}
	else if (toRight(&new_node->item, &root->item))
	{
		if (NULL == root->right_node)		//空右子树
		{
			root->right_node = new_node;	//添加到右子树
		}
		else
		{
			addNode(new_node, root->right_node);
		}
	}
	else
	{
		//不应含有相同的项目
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
		return false;										//不在左子树,或者与根结点相等
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
		return false;										//不在右子树,或者与根结点相等
	}
}

static Pair seekItem(const Item * pi, const Tree * ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;								//初始化的时候从根结点开始

	if (NULL == look.child)
	{
		return look;										//提前返回
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
			break;											//look.child是目标项目结点的地址
		}
	}
	return look;											//成功返回
}

static void deleteNode(Node ** ptr)
{
	Node * temp;

	fputs((*ptr)->item.petName, stdout);
	if (NULL == (*ptr)->left_node)							//左子树为空
	{
		temp = *ptr;
		*ptr = (*ptr)->right_node;
		free(temp);
	}
	else if (NULL == (*ptr)->right_node)					//右子树为空
	{
		temp = *ptr;
		*ptr = (*ptr)->left_node;
		free(temp);
	}
	else													//左,右子树都不为空
	{
		//找到右子树的依附位置
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
		//先释放存储宠物类型的单链表

		free(root);
		deleteAllNode(pringht);
	}
}
