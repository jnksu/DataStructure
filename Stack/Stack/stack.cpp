//ʵ��ջ�ӿ�
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

//�ֲ�����ԭ��
static void copyToArr(Item * tpi, const Item * spi);

//ջ�ӿں���ʵ��
void InitializeStack(Stack * ps)
{
	ps->arr = (Item *)malloc(MAXITEMS * sizeof(Item));
	ps->stack_top = -1;			//����ջ��
}

bool StackIsEmpty(const Stack * ps)
{
	return -1 == ps->stack_top;
}

bool StackIsFull(const Stack * ps)
{
	return (MAXITEMS - 1) == ps->stack_top;
}

unsigned int StackItemCount(const Stack * ps)
{
	return ps->stack_top + 1;
}

bool Push(Stack * ps, const Item * pi)
{
	if (StackIsFull(ps) || NULL == pi)
	{
		return false;
	}
	else
	{
		ps->stack_top++;
		copyToArr((ps->arr) + ps->stack_top, pi);
		return true;
	}
}

bool Pop(Item * pi, Stack * ps)
{

	if (StackIsEmpty(ps) || NULL == pi)
	{
		return false;
	}
	else
	{
		*pi = (ps->arr)[ps->stack_top];
		ps->stack_top--;
		return true;
	}
}

void DeleteAll(Stack * ps)
{
	free(ps->arr);
	ps->stack_top = -1;
}

//�ֲ�����ʵ��
static void copyToArr(Item * tpi, const Item * spi)
{
	*tpi = *spi;
}
