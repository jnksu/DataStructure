/* linkList.h -- ����������ͷ�ļ� */
#ifndef LINKLIST_H_
#define LINKLIST_H_
/* ͷ���ӿ� */
#include "Node.h"
/* �������   */
#include <inttypes.h>
#define APP_MAX INT32_MAX //������� 
/* �ӿں���ԭ�� */

/* ����:����յ�����,����ͷ���   */
/* ����ǰ: �������              */
/* ������: ����һ��ָ��յ�      */
/* ͷ���.                      */
Head CreateNullLinkList(void);

/* ����:��ָ�������еĶ������  */
/* ���쵥����,����β���빹�쵥  */
/* ����.                        */
/* ����ǰ:elmentָ��Ҫ���������*/
/* ������:����ɹ��򷵻�ָ�����*/
/* ��ָ��,���򷵻ؿ�ָ��        */
Node * CreateNullLinkList(Data * element, int size);

/* ����:����һ��������          */
/* ����ǰ:listָ������Ƶ�����  */
/* ������:������Ƴɹ��򷵻�ָ  */
/* ���Ƴɹ��������ͷָ��,��  */
/* �򷵻ؿ�ָ��                 */
Head  CopyOfLinkList(const Head * list);

/* ����:�ж������Ƿ�Ϊ��        */
/* ����ǰ:list Ϊ���жϵ�����   */
/* ������:�������Ϊ���򷵻���  */
/* ���򷵻ؼ�                   */
bool LinkListIsEmpty(const Head * list);

/* ����: ���ص�����ĳ���       */
/* ����ǰ: listΪ�����������   */
/* ������: ����������ĸ���   */
unsigned int Length_LinkList(const Head * list);

/* ����:��õ�����ĳ��Ԫ��      */
/* ����ǰ:listΪԪ�����ڵ�����  */
/* posΪԪ�ص�λ��              */
/* ������:��������򷵻ظý��  */
/* ��ָ��,���򷵻ؿ�ָ��        */
Node * GetData_LinkList(const Head * list, int pos);

/* ����:���õ�����ĳ��Ԫ��      */
/* ����ǰ: listΪҪ���õ�����   */
/* posΪ����λ��,elemΪҪ�滻 */
/* ��Ԫ��                       */
/* ������:������óɹ��򷵻�    */
/* true���򷵻�false            */
bool SetData_LinkList(const Head * list, int pos, Data elem);

/* ����:��ĳ��λ�ò���Ԫ��      */
/* ����ǰ: listΪҪ����Ԫ��     */
/* ������,pos Ϊ����λ��elem  */
/* ΪҪ�����Ԫ��               */
/* ������:�������ɹ���        */
/* ������,���򷵻ؼ�            */
void Insert_LinkList(Head * list, int pos, Data elem);

/* ����:�ڵ�������׷�ӽ��      */
/* ����ǰ:elem Ҫ׷�ӵ�Ԫ��     */
/* ������:��Ԫ�ؼ�������        */
void AppendNode_LinkList(Head * list, Data elem);

/* ����:ɾ��ĳ�����            */
/* ����ǰ:listҪ����������,pos  */
/* Ҫɾ���Ľ��λ��             */
/* ������: ���ɾ���ɹ��򷵻�   */
/* ָ��ɾ������ָ��,���򷵻ؿ�*/
/* ָ��                         */
Node * RemovedNode_LinkList(Head * list, int pos);

/* ����:�Ƴ�����������н��    */
/* ����ǰ:listָ��Ҫɾ������    */
/* ��������                   */
/* ������: �������н�㱻����   */
void RemoveAllNode_LinkList(Head * list);

/* ����:˳����ҹؼ���Ϊkey��ֵ */
/* ����ǰ:list::Ҫ���в��ҵ�����*/
/* ������:���ص�һ�����ҵ���Ԫ��*/
/* �Ľ��ָ��                  */
Node * SearchNode(const Head * list, Data key);

/* ����:�Ƚϵ������Ƿ����  */
/* ����ǰ: av_list,av_list */
/* ָ��������Ҫ�Ƚϵ�����   */
/* ������:  �����ȷ�����  */
/* ���򷵻ؽ��Ϊ��         */
bool Equals_LinkList(const Head * av_list, const Head * av_list1);

/* ����:�������������нڵ� */
/* ����ǰ:av_listҪ���������*/
/* ������:�ڱ�׼��������   */
/* ���.                    */
void toString_LinkList(const Head * av_list);

/* ����:��ĳ���ڵ��ǰ�����  */
/* ����ǰ: listΪ��Ѱ������   */
/* posΪ���λ��             */
/* ������: Ѱ�ҳɹ��򷵻�ָ�� */
/* ���ҵ�����ָ��,���򷵻ؿ�*/
/* ָ��                      */
Node * GetPioneer_LinkList(const Head * list, int pos);

/* ����:��ĳ���ĺ�̽��    */
/* ����ǰ: listΪ��Ѱ������   */
/* posΪ���λ��             */
/* ������: Ѱ�ҳ¹��򷵻�ָ�� */
/* ���ҵ���ָ��,���򷵻ؿ�ָ��*/
Node * GetSucceed_LinkList(const Head * list, int pos);

/* ����:��ת����             */
/* ����ǰ:listָ�����ת������*/
/* ������: ������ת         */
void Reverse_LinkList(Head * list);

/* ����:��������                */
/* ����ǰ: listΪ�����ٵ�����   */
/* ������: ����ռ�õ��ڴ汻�ͷ� */

void destroylinkList(Head * list);
#endif