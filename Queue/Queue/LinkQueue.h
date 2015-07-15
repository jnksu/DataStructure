/* LinkQueue.h -- 链式队列接口 */
#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_
#include <stdbool.h>
#include "Node.h"			//包含队列使用的数据
/* 表示链式队列的数据结构 */
struct link_queue_Node 
{
	Data elem;				
	struct link_queue_Node * next;	
};

typedef struct link_queue_Node  LinkQueueNode;

//表示队列的数据结构
struct Link_queue
{
	LinkQueueNode * head;			//头结点
	LinkQueueNode * tail;			//尾结点
};

typedef struct Link_queue Head;

/* 函数原型               */

/* 操作:构造一个空队列     */
/* 操作前:无              */
/* 操作后:返回一个指向队   */
/* 列头结点的指针         */
Head * createLinkQueue(void);

/* 操作:判断队列是否为空         */
/* 操作前:av_queue为要判断的队列 */
/* 操作后:如果队列为空则返回真    */
/* 否则返回假                    */
bool LinkQueueIsEmpty(const Head * av_queue);

/* 操作:获得当前队列中元素的个数 */
/* 操作前:av_queue为要使用的队列 */
/* 操作后:返回队列中元素的个数   */
unsigned int countLinkQueue(const Head * av_queue);

/* 操作:元素入队                 */
/* 操作前:elem入队元素,av_queue  */
/* 要使用的元素                  */
/* 操作后:如果入队成功则返回真,否 */
/* 则返回假                      */
bool EnLinkQueue(Head * av_queue, Data elem);
/* 操作:元素出队                  */
/* 操作前:av_queue出队队列        */
/* 操作后:如果出队成功,返回出队元素*/
/* 指针,否则返回空指针            */
LinkQueueNode * DeLinkQueue(Head * av_queue);

/* 操作:输出队列当前情况         */
/* 操作前:av_queue使用队列      */
/* 操作后:输出当前队列情况       */
void toStringLinkQueue(const Head * av_queue);

/* 操作:反转队列                 */
/* 操作前:av_list要使用的队列   */
/* 操作后:队列被反转             */
void reserveLinkQueue(Head * av_queue);

/* 操作:销毁一个队列             */
/* 操作前:av_queue为要销毁的队列 */
/* 操作后:队列全部被销毁         */
void destroyLinkQueue(Head * av_queue);
#endif
