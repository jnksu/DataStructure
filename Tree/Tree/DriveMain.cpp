//petclub.c -- 使用二叉搜索树
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "debug.h"

char menu(void);
void addPet(Tree * pt);
void dropPet(Tree * pt);
void showPets(const Tree * pt);
void findPet(const Tree * pt);
void printItem(Item item);
void upperCase(char * str);
void reject_ch(char * str, int ch);

int main(int argc, char ** argv)
{
	Tree pets;
	char choice;

	InitializeTree(&pets);
	while ((choice = menu()) != 'q')
	{
		switch (choice)
		{
		case 'a': addPet(&pets);							//添加一个宠物
			break;
		case 'l': showPets(&pets);							//输出所有宠物的信息
			break;
		case 'f': findPet(&pets);							//查找宠物
			break;
		case 'n': printf("%d pets in club\n",				//计算宠物的个数
			TreeItemCount(&pets));
			break;
		case 'd': dropPet(&pets);							//删除某个宠物
			break;
		default: fputs("Switching error\n", stdout);
			break;
		}
	}
	DeleteAll(&pets);
	fputs("Bye!\n", stdout);

	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}

char menu(void)
{
	int ch;

	fputs("Nerfville Pet Club Membership Program.\n", stdout);
	fputs("Enter the letter corresponding to your choice:\n", stdout);
	fputs("a) add a pet         l) show list of pets\n", stdout);
	fputs("n) number of pets    f)find pets\n", stdout);
	fputs("d)delete a pet  list     q)quit\n", stdout);

	while ((ch = getchar()) != EOF)
	{
		//丢弃输入行的剩余部分
		while (getchar() != '\n')
		{
			continue;
		}
		ch = tolower(ch);
		if (NULL == strchr("alnfdq", ch))
		{
			fputs("Please enter an a, l, n, f, d, q.\n", stdout);
		}
		else
		{
			break;
		}
	}
	if (EOF == ch)
		ch = 'q';
	return ch;
}

void addPet(Tree * pt)
{
	Item temp;

	if (TreeIsFull(pt))
	{
		fputs("No room in the club!\n", stdout);
	}
	else
	{
		fputs("Please enter name of pet: ", stdout);
		fgets(temp.petName, STRLEN, stdin);
		reject_ch(temp.petName, '\n');

		fputs("Please enter pet kind: ", stdout);
		fgets(temp.petKind, STRLEN, stdin);
		reject_ch(temp.petKind, '\n');

		upperCase(temp.petName);
		upperCase(temp.petKind);
		AddItem(&temp, pt);
	}
}
void dropPet(Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		fputs("No entries!\n", stdout);
		return;								//如果树为空树,退出程序
	}

	fputs("Please enter the name of pet you wish to find:\n", stdout);
	fgets(temp.petName, STRLEN, stdin);
	reject_ch(temp.petName, '\n');

	upperCase(temp.petName);
	upperCase(temp.petKind);

	printf("%s the %s ", temp.petName, temp.petKind);
	if (DeleteItem(&temp, pt))
	{
		printf("is dropped from the club.\n");
	}
	else
	{
		printf("is not a member.\n");
	}
}

void showPets(const Tree * pt)
{
	if (TreeIsEmpty(pt))
	{
		fputs("No entries!\n", stdout);
	}
	else
	{
		Traverse(pt, printItem);
	}
}
void findPet(const Tree * pt)
{
	Item temp;

	if (TreeIsEmpty(pt))
	{
		fputs("No entries!\n", stdout);
		return;
	}

	fputs("Please enter the name of pet you wish to find:\n", stdout);
	fgets(temp.petName, STRLEN, stdin);
	reject_ch(temp.petName, '\n');

	upperCase(temp.petName);
	upperCase(temp.petKind);

	printf("%s the %s ", temp.petName, temp.petKind);
	if (Intree(&temp, pt))
	{
		printf("is a member.\n");
	}
	else
	{
		printf("is not a member.\n");
	}
}

void printItem(Item item)
{
	printf("Pet: %-19s\n", item.petName);
	for (int i = 0; i < item.ListLen; i++)
	{
		printf("Pet Kind %-19s\n", item.ArrPetKind[i]);
	}
}

void upperCase(char * str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}
void  reject_ch(char * str, int ch)
{
	char * match;

	match = strchr(str, ch);

	if (match)
		*match = '\0';
}