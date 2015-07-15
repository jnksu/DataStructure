// stack.h --  栈类型的接口
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

//用户自定义项目类型
typedef struct item
{
	char letter;
} Item;

//栈的大小
#define MAXITEMS 80

//栈结构
typedef struct stack
{
	Item * arr;					//指向栈的数组
	unsigned int stack_top;		//栈顶
} Stack;

//操作:把一个栈初始化为空栈
//操作前:ps指向一个栈
//操作后:该栈被初始化为空栈
void InitializeStack(Stack * ps);

//操作:检查栈是否为空
//操作前:ps指向一个已经初始化的栈
//操作后:如果栈为空,则返回true,否则返回false
bool StackIsEmpty(const Stack * ps);

//操作:检查栈是否已满
//操作前:ps指向一个已经初始化的栈
//操作后:如果栈已满,则返回true,否则返回false
bool StackIsFull(const Stack * ps);

//操作:确定栈中项目的个数
//操作前:ps指向一个已经初始化的栈
//操作后:返回栈中项目的个数
unsigned int StackItemCount(const Stack * ps);

//操作:元素入栈
//操作前:pi指向要入栈的项目,ps指向已经初始化的栈
//操作后:如果元素入栈成功,则返回true,否则返回false
bool Push(Stack * ps, const Item * pi);

//操作:元素出栈
//操作前:pi指向要出栈的元素,ps指向已经初始化的栈
//操作后:如果出栈成功则,pi指向已经出栈的元素,返回true,否则pi为NULL返回false
bool Pop(Item * pi, Stack * ps);

//操作:清空栈
//操作前:ps指向要清空栈(ps已经初始化)
//操作后:栈被清空
void DeleteAll(Stack * ps);

#endif
