// stack.h --  ջ���͵Ľӿ�
#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

//�û��Զ�����Ŀ����
typedef struct item
{
	char letter;
} Item;

//ջ�Ĵ�С
#define MAXITEMS 80

//ջ�ṹ
typedef struct stack
{
	Item * arr;					//ָ��ջ������
	unsigned int stack_top;		//ջ��
} Stack;

//����:��һ��ջ��ʼ��Ϊ��ջ
//����ǰ:psָ��һ��ջ
//������:��ջ����ʼ��Ϊ��ջ
void InitializeStack(Stack * ps);

//����:���ջ�Ƿ�Ϊ��
//����ǰ:psָ��һ���Ѿ���ʼ����ջ
//������:���ջΪ��,�򷵻�true,���򷵻�false
bool StackIsEmpty(const Stack * ps);

//����:���ջ�Ƿ�����
//����ǰ:psָ��һ���Ѿ���ʼ����ջ
//������:���ջ����,�򷵻�true,���򷵻�false
bool StackIsFull(const Stack * ps);

//����:ȷ��ջ����Ŀ�ĸ���
//����ǰ:psָ��һ���Ѿ���ʼ����ջ
//������:����ջ����Ŀ�ĸ���
unsigned int StackItemCount(const Stack * ps);

//����:Ԫ����ջ
//����ǰ:piָ��Ҫ��ջ����Ŀ,psָ���Ѿ���ʼ����ջ
//������:���Ԫ����ջ�ɹ�,�򷵻�true,���򷵻�false
bool Push(Stack * ps, const Item * pi);

//����:Ԫ�س�ջ
//����ǰ:piָ��Ҫ��ջ��Ԫ��,psָ���Ѿ���ʼ����ջ
//������:�����ջ�ɹ���,piָ���Ѿ���ջ��Ԫ��,����true,����piΪNULL����false
bool Pop(Item * pi, Stack * ps);

//����:���ջ
//����ǰ:psָ��Ҫ���ջ(ps�Ѿ���ʼ��)
//������:ջ�����
void DeleteAll(Stack * ps);

#endif
