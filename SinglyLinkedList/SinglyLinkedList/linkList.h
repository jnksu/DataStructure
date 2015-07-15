/* linkList.h -- 创建链表打的头文件 */
#ifndef LINKLIST_H_
#define LINKLIST_H_
/* 头结点接口 */
#include "Node.h"
/* 最大整数   */
#include <inttypes.h>
#define APP_MAX INT32_MAX //最大整数 
/* 接口函数原型 */

/* 操作:构造空单链表,创建头结点   */
/* 操作前: 无需参数              */
/* 操作后: 返回一个指向空的      */
/* 头结点.                      */
Head CreateNullLinkList(void);

/* 操作:由指定数组中的多个对象  */
/* 构造单链表,采用尾插入构造单  */
/* 链表.                        */
/* 操作前:elment指向要插入的数组*/
/* 操作后:如果成功则返回指向该链*/
/* 的指针,否则返回空指针        */
Node * CreateNullLinkList(Data * element, int size);

/* 操作:复制一个单链表          */
/* 操作前:list指向待复制的链表  */
/* 操作后:如果复制成功则返回指  */
/* 向复制成功的链表的头指针,否  */
/* 则返回空指针                 */
Head  CopyOfLinkList(const Head * list);

/* 操作:判断链表是否为空        */
/* 操作前:list 为待判断的链表   */
/* 操作后:如果链表为空则返回真  */
/* 否则返回假                   */
bool LinkListIsEmpty(const Head * list);

/* 操作: 返回单链表的长度       */
/* 操作前: list为待计算的链表   */
/* 操作后: 返回链表结点的个数   */
unsigned int Length_LinkList(const Head * list);

/* 操作:获得单链表某个元素      */
/* 操作前:list为元素所在的链表  */
/* pos为元素的位置              */
/* 操作后:如果存在则返回该结点  */
/* 的指针,否则返回空指针        */
Node * GetData_LinkList(const Head * list, int pos);

/* 操作:设置单链表某个元素      */
/* 操作前: list为要设置的链表   */
/* pos为结点的位置,elem为要替换 */
/* 的元素                       */
/* 操作后:如果设置成功则返回    */
/* true否则返回false            */
bool SetData_LinkList(const Head * list, int pos, Data elem);

/* 操作:在某个位置插入元素      */
/* 操作前: list为要插入元素     */
/* 的链表,pos 为结点的位置elem  */
/* 为要插入的元素               */
/* 操作后:如果插入成功则        */
/* 返回真,否则返回假            */
void Insert_LinkList(Head * list, int pos, Data elem);

/* 操作:在单链表中追加结点      */
/* 操作前:elem 要追加的元素     */
/* 操作后:将元素加入链表        */
void AppendNode_LinkList(Head * list, Data elem);

/* 操作:删除某个结点            */
/* 操作前:list要操作的链表,pos  */
/* 要删除的结点位置             */
/* 操作后: 如果删除成功则返回   */
/* 指向删除结点的指针,否则返回空*/
/* 指针                         */
Node * RemovedNode_LinkList(Head * list, int pos);

/* 操作:移除单链表的所有结点    */
/* 操作前:list指向要删除所有    */
/* 结点的链表                   */
/* 操作后: 链表所有结点被销毁   */
void RemoveAllNode_LinkList(Head * list);

/* 操作:顺序查找关键字为key的值 */
/* 操作前:list::要进行查找的链表*/
/* 操作后:返回第一个查找到的元素*/
/* 的结点指针                  */
Node * SearchNode(const Head * list, Data key);

/* 操作:比较单链表是否相等  */
/* 操作前: av_list,av_list */
/* 指向两个将要比较的链表   */
/* 操作后:  如果相等返回真  */
/* 否则返回结果为假         */
bool Equals_LinkList(const Head * av_list, const Head * av_list1);

/* 操作:输出单链表的所有节点 */
/* 操作前:av_list要输出的链表*/
/* 操作后:在标准输出流输出   */
/* 结果.                    */
void toString_LinkList(const Head * av_list);

/* 操作:求某个节点的前驱结点  */
/* 操作前: list为待寻找链表   */
/* pos为结点位置             */
/* 操作后: 寻找成功则返回指向 */
/* 查找到结点的指针,否则返回空*/
/* 指针                      */
Node * GetPioneer_LinkList(const Head * list, int pos);

/* 操作:求某结点的后继结点    */
/* 操作前: list为待寻找链表   */
/* pos为结点位置             */
/* 操作后: 寻找陈功则返回指向 */
/* 查找到的指针,否则返回空指针*/
Node * GetSucceed_LinkList(const Head * list, int pos);

/* 操作:反转链表             */
/* 操作前:list指向待反转的链表*/
/* 操作后: 链表被反转         */
void Reverse_LinkList(Head * list);

/* 操作:销毁链表                */
/* 操作前: list为待销毁的链表   */
/* 操作后: 链表占用的内存被释放 */

void destroylinkList(Head * list);
#endif