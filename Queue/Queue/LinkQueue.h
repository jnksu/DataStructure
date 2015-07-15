/* LinkQueue.h -- ��ʽ���нӿ� */
#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_
#include <stdbool.h>
#include "Node.h"			//��������ʹ�õ�����
/* ��ʾ��ʽ���е����ݽṹ */
struct link_queue_Node 
{
	Data elem;				
	struct link_queue_Node * next;	
};

typedef struct link_queue_Node  LinkQueueNode;

//��ʾ���е����ݽṹ
struct Link_queue
{
	LinkQueueNode * head;			//ͷ���
	LinkQueueNode * tail;			//β���
};

typedef struct Link_queue Head;

/* ����ԭ��               */

/* ����:����һ���ն���     */
/* ����ǰ:��              */
/* ������:����һ��ָ���   */
/* ��ͷ����ָ��         */
Head * createLinkQueue(void);

/* ����:�ж϶����Ƿ�Ϊ��         */
/* ����ǰ:av_queueΪҪ�жϵĶ��� */
/* ������:�������Ϊ���򷵻���    */
/* ���򷵻ؼ�                    */
bool LinkQueueIsEmpty(const Head * av_queue);

/* ����:��õ�ǰ������Ԫ�صĸ��� */
/* ����ǰ:av_queueΪҪʹ�õĶ��� */
/* ������:���ض�����Ԫ�صĸ���   */
unsigned int countLinkQueue(const Head * av_queue);

/* ����:Ԫ�����                 */
/* ����ǰ:elem���Ԫ��,av_queue  */
/* Ҫʹ�õ�Ԫ��                  */
/* ������:�����ӳɹ��򷵻���,�� */
/* �򷵻ؼ�                      */
bool EnLinkQueue(Head * av_queue, Data elem);
/* ����:Ԫ�س���                  */
/* ����ǰ:av_queue���Ӷ���        */
/* ������:������ӳɹ�,���س���Ԫ��*/
/* ָ��,���򷵻ؿ�ָ��            */
LinkQueueNode * DeLinkQueue(Head * av_queue);

/* ����:������е�ǰ���         */
/* ����ǰ:av_queueʹ�ö���      */
/* ������:�����ǰ�������       */
void toStringLinkQueue(const Head * av_queue);

/* ����:��ת����                 */
/* ����ǰ:av_listҪʹ�õĶ���   */
/* ������:���б���ת             */
void reserveLinkQueue(Head * av_queue);

/* ����:����һ������             */
/* ����ǰ:av_queueΪҪ���ٵĶ��� */
/* ������:����ȫ��������         */
void destroyLinkQueue(Head * av_queue);
#endif
