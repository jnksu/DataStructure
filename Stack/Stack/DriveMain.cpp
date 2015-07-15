//��������
#include "debug.h"
#include "stack.h"
#include <string.h>
#define STRLEN 81
//�ֲ�����ԭ��
static void reject_ch(char * str, int ch);

int main(int argc, char ** argv)
{
	Stack test;
	Item temp;
	char arr[STRLEN];
	char * pc = NULL;

	InitializeStack(&test);
	fputs("Enter the string(empty line to quit):\n", stdout);
	
	while (fgets(arr, STRLEN, stdin) && arr[0] != '\n')
	{
		reject_ch(arr, '\n');
		pc = arr;
		//�ַ�����ջ
		while (*pc)
		{
			temp.letter = *pc++;
			Push(&test, &temp);
		}
		//�ַ�����ջ
		while (!StackIsEmpty(&test))
		{
			Pop(&temp, &test);
			putchar(temp.letter);
		}
		putchar('\n');
		fputs("Enter the string(empty line to quit):\n", stdout);
	}

	//�����ڴ�й©
	DeleteAll(&test);
	_CrtDumpMemoryLeaks();
	fputs("Bye~!\n", stdout);
	getchar();
	return EXIT_SUCCESS;
}

//�ֲ�����
static void  reject_ch(char * str, int ch)
{
	char * match;

	match = strchr(str, ch);

	if (match)
		*match = '\0';
}