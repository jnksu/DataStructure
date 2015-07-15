/* queue.h -- ���нӿ�  */
#ifndef LOOPQUEUE_H_
#define LOOPQUEUE_H_
#include <stdbool.h>
#include "Node.h"		//��������ʹ�õ����ݽṹ

/* ��ʾ���е����ݽṹ */
struct loop_queue
{
	unsigned int Adelete;	//�Ѿ�ɾ����Ԫ�ص�λ��
	unsigned int Wadd;		//��Ҫ���Ԫ�ص�λ��
	Data * queue;			//ָ����е�ָ��
	unsigned int queue_size;//���еĴ�С
};

typedef struct loop_queue LoopQueue;
/* ����ԭ��                     */

/* ����:����һ��ָ�����ȵĶ���   */
/* ����ǰ:len ΪҪ������еĳ��� */
/* ������: ����ָ����е�ָ��    */
LoopQueue * createLoopQueue(unsigned int len);

/* ����:�ж϶����Ƿ�Ϊ��         */
/* ����ǰ:av_queueΪҪ�жϵĶ��� */
/* ������:�������Ϊ���򷵻���    */
/* ���򷵻ؼ�                    */
bool LoopQueueIsEmpty(const LoopQueue * av_queue);

/* ����:��õ�ǰ������Ԫ�صĸ��� */
/* ����ǰ:av_queueΪҪʹ�õĶ��� */
/* ������:���ض�����Ԫ�صĸ���   */
unsigned int countLoopQueue(const LoopQueue * av_queue);

/* ����:Ԫ�����                 */
/* ����ǰ:elem���Ԫ��,av_queue  */
/* Ҫʹ�õ�Ԫ��                  */
/* ������:�����ӳɹ��򷵻���,�� */
/* �򷵻ؼ�                      */
bool EnLoopQueue(LoopQueue * av_queue, Data elem);

/* ����:Ԫ�س���                  */
/* ����ǰ:av_queue���Ӷ���        */
/* ������:������ӳɹ�,���س���Ԫ��*/
/* ָ��,���򷵻ؿ�ָ��            */
Data * DeLoopQueue(LoopQueue * av_queue);

/* ����:������е�ǰ���         */
/* ����ǰ:av_queueʹ�ö���      */
/* ������:�����ǰ�������       */
void toStringLoopQueue(const LoopQueue * av_queue);

/* ����:��ת����                 */
/* ����ǰ:av_listҪʹ�õĶ���   */
/* ������:���б���ת             */
void reserveLoopQueue(LoopQueue * av_queue);

/* ����:����һ������             */
/* ����ǰ:av_queueΪҪ���ٵĶ��� */
/* ������:����ȫ��������         */
void destroyLoopQueue(LoopQueue * av_queue);

/* ����:�ж϶����Ƿ�����         */
/* ����ǰ:av_queueΪҪ�жϵĶ��� */
/* ������:�������������         */
bool LoopQueueIsFull(const LoopQueue * av_queue);
#endif
