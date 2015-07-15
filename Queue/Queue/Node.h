/* Node.h -- 用于队列的数据结构 */

#ifndef NODE_H_
#define NODE_H_

/* 特定于程序的声明 */
struct originalSet
{
	//用户自定义的数据类型
	long arrive;				/* 一位顾客加入队列时的时间 */
	int process_time;			/* 该顾客需要咨询时间		*/
};

/* 数据域           */
typedef struct originalSet Data;

#endif
