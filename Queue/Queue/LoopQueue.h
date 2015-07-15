/* queue.h -- 队列接口  */
#ifndef LOOPQUEUE_H_
#define LOOPQUEUE_H_
#include <stdbool.h>
#include "Node.h"		//包含队列使用的数据结构

/* 表示队列的数据结构 */
struct loop_queue
{
	unsigned int Adelete;	//已经删除的元素的位置
	unsigned int Wadd;		//将要添加元素的位置
	Data * queue;			//指向队列的指针
	unsigned int queue_size;//队列的大小
};

typedef struct loop_queue LoopQueue;
/* 函数原型                     */

/* 操作:构造一个指定长度的队列   */
/* 操作前:len 为要构造队列的长度 */
/* 操作后: 返回指向队列的指针    */
LoopQueue * createLoopQueue(unsigned int len);

/* 操作:判断队列是否为空         */
/* 操作前:av_queue为要判断的队列 */
/* 操作后:如果队列为空则返回真    */
/* 否则返回假                    */
bool LoopQueueIsEmpty(const LoopQueue * av_queue);

/* 操作:获得当前队列中元素的个数 */
/* 操作前:av_queue为要使用的队列 */
/* 操作后:返回队列中元素的个数   */
unsigned int countLoopQueue(const LoopQueue * av_queue);

/* 操作:元素入队                 */
/* 操作前:elem入队元素,av_queue  */
/* 要使用的元素                  */
/* 操作后:如果入队成功则返回真,否 */
/* 则返回假                      */
bool EnLoopQueue(LoopQueue * av_queue, Data elem);

/* 操作:元素出队                  */
/* 操作前:av_queue出队队列        */
/* 操作后:如果出队成功,返回出队元素*/
/* 指针,否则返回空指针            */
Data * DeLoopQueue(LoopQueue * av_queue);

/* 操作:输出队列当前情况         */
/* 操作前:av_queue使用队列      */
/* 操作后:输出当前队列情况       */
void toStringLoopQueue(const LoopQueue * av_queue);

/* 操作:反转队列                 */
/* 操作前:av_list要使用的队列   */
/* 操作后:队列被反转             */
void reserveLoopQueue(LoopQueue * av_queue);

/* 操作:销毁一个队列             */
/* 操作前:av_queue为要销毁的队列 */
/* 操作后:队列全部被销毁         */
void destroyLoopQueue(LoopQueue * av_queue);

/* 操作:判断队列是否已满         */
/* 操作前:av_queue为要判断的队列 */
/* 操作后:如果已满返回真         */
bool LoopQueueIsFull(const LoopQueue * av_queue);
#endif
