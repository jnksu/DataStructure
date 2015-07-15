//tree.h -- 二叉搜索树		
//树中不允许有相同的项目	
#ifndef _TREE_H_
#define _TREE_H_

#define STRLEN 20		//最大字符串长度
#define MAXITEMS 10     //二叉树结点最大个数
#define MAXARRLEN 30	//顺序表最大长度

#include <stdbool.h>

//可以把Item重新定义为合适的类型
typedef struct item
{
	char petName[STRLEN];
	char petKind[STRLEN];
	char ArrPetKind[MAXARRLEN][STRLEN];					//采用二微数组存储宠物类型
	int ListLen;										//记录顺序表中元素的个数
}Item;

//定义二叉树结点
typedef struct node
{
	Item item;
	struct node * left_node;
	struct node * right_node;
}Node;

typedef struct tree
{
	Node * root;				//指向根结点的指针
	unsigned int size;			//树中项目的个数	
}Tree;

//函数原型 
//操作:把一个树初始化为空树
//操作前:ptree指向一个树
//操作后:该树已被初始化为空树
void InitializeTree(Tree * ptree);

//操作:确定树是否为空树
//操作前:ptree指向一个树
//操作后:如果树为空树返回true;否则返回false
bool TreeIsEmpty(const Tree * ptree);

//操作:确定树是否已满
//操作前:ptree指向一个树
//操作后:如果树已满则返回true;否则返回false
bool TreeIsFull(const Tree * ptree);

//操作:确定树中项目的个数
//操作前:ptree指向一个树
//操作后:函数返回树中项目的个数
unsigned int TreeItemCount(const Tree * ptree);

//操作:向树中添加一个项目***
//操作前:pi是待添加的项目的地址
//      ptree指向一个已经初始化的树
//操作后:如果可能,函数把该项目
//		添加到树中并返回true
//		否则函数返回false
bool AddItem(const Item * pi, Tree * ptree);

//操作:在树中查找一个项目 
//操作前:pi指向一个项目
//		 ptree指向一个已经初始化的树
//操作后:如果在该树中存在相应项目,则函数返回true
//		 否则返回false
bool Intree(const Item * pi, const Tree * ptree);

//操作:从树中删除一个项目
//操作前:pi是待删除的项目的地址
//		 ptree指向一个已经初始化的树
//操作后:如果可能,函数从树中删除该项目
//		 并返回true,否则函数返回false
bool DeleteItem(const Item * pi, Tree * ptree);

//操作:在树中搜索相应的项目
//操作前:pi指向一个项目,
//		 ptree指向一个已经初始化的树
//操作后:如果在树中存在该项目,返回树中相应项目的指针
//		否则返回NULL
const Item * seekInTree(const Tree * ptree, Item * pi);

//操作:把一个函数作用于树中的每一个项目
//操作前:ptree指向一棵树
//		 pfun指向一个没有返回值的函数
//		 该函数接受一个Item作为参数
//操作后:pfun指向的函数被作用于
//		树中的每个项目一次
void Traverse(const Tree * ptree, void (* pfun)(Item item));

//操作:从树中删除结点
//操作前:ptree指向一个已经初始化的树
//操作后:该树为空
void DeleteAll(Tree * ptree);
#endif 
