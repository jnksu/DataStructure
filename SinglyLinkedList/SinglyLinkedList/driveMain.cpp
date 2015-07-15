/* driveMain.cpp -- ����һ������ADT���������� */
#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"

/* �ڴ�й©��� */
#include <stdlib.h>
#include <crtdbg.h>

int main(int argc, char ** argv)
{
	Data arr[] = {
		{ 1 },
		{ 2 },
		{ 3 },
		{ 4 },
		{ 5 },
		{ 6 } };

	Node * list = CreateNullLinkList(arr, 6);
	toString_LinkList(&list);
	
	Reverse_LinkList(&list);
	toString_LinkList(&list);

	//��������
	RemoveAllNode_LinkList(&list);

	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}
