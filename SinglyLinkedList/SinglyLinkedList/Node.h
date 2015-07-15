/* Node.h -- 创建链表节点的头文件 */
#ifndef NODE_H_
#define NODE_H_
#include <stdbool.h>

/* 特定于程序的声明 */
struct originalSet
{
	//用户自定义的数据类型
	int TestNum;
};

/* 数据域           */
typedef struct originalSet Data;

/* 节点模板         */
typedef struct node
{
	Data data;
	struct node * next;	//指针域
}Node;

/* 头节点指针       */
typedef Node * Head;

/* 接口函数原型     */

/* 操作:创建指向next,存有Data的节点 */
/* 操作前: next 指向下一个节点,Data */
/* 为节点数据域                     */
/* 操作后: 如果创建成功,则返回指向  */
/* 创建节点的指针,否则返回空指针    */
Node * CreateNode(Data av_data, Node * av_next);

/* 操作:比较两个节点是否相等        */
/* 操作前: p_node, p_node1分别为要  */
/* 进行比较的两个节点的指针         */
/* 操作后: 如果两个指针相等返回真   */
/* 否则返回假                       */
bool Equals_Node(const Data elem, const Node * av_node1);

#endif
