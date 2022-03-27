#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../head/LinkStack.h" 

int main()
{
	show();
	return 0;
}

void show()
{
	LinkStack *s=(LinkStack*)malloc(sizeof(LinkStack));
	if(initLStack(s) == ERROR)
		exit(-1);
	int flag=0;
	int data;
	int length;
	while(1)
	{
		while(1)
		{
			flag = 0;
			printf("You can do these function:\n");
			printf("1.Check whether the stack is empty;\n");
			printf("2.Get the number of the top of stack;\n");
			printf("3.Get the lenth of the stack;\n");
			printf("4.Push a number into the stack;\n");
			printf("5.Pop a number from the stack;\n");
			printf("6.Destroy the stakc and quit.\n");
			printf("Now you can give me the number before the funtion:\n");
			scanf("%d", &flag);
			while(getchar() != '\n');
			if(flag>6 || flag <1)
			{
				system("cls");
				printf("Please give me the right number!\n");
			}
			else
				break;
		}
		switch(flag)
		{
			case(1):
				if(isEmptyLStack(s) == ERROR)
					printf("It is not an empty stack.\n");
				else
					printf("It is an empty stack.\n");
				break;
			case(2):
				if(getTopLStack(s, &data) == ERROR)
					printf("Now there is no number in the stack,you should add some number into it!\n");
				else
					printf("The number of the top we pop is %d.\n", data);
				break;
			case(3):
				if(LStackLength(s, &length) == SUCCESS)
					printf("The length of the stack is %d.\n", length);
				else
				{
					printf("Now there is something wrong in the stack!!!\n");
					exit(-1);
				}
				break;
			case(4):
				data=10000;
				printf("Please give me a number you want to push into the stack:\n");
				getAllInt(&data);
				if(pushLStack(s, data) == ERROR)
				{
					printf("The room is full!!!\n");
					exit(-1);
				}
				else
					printf("We have pushed it into stcak.\n");
				break;
			case(5):
				data=0;
				if(popLStack(s, &data) == SUCCESS)
					printf("We have popped the node whose number is %d.\n", data);
				else
					printf("There is no number in the stack and you should add some number into it!\n");
				break;
			case(6):
				clearLStack(s);
				destroyLStack(s);
				return;
		}
	printf("Give me anything to continue:\n");
	while(getchar() != '\n');
	system("cls");
	}
}

/* 获取一个属于(0,10000)的int 数据 */  
void getInt(int *a)
{
	char s[50];
	int flag=1;
	while(1)
	{
		gets(s);
		if(strlen(s) <= 5)
		{
			int i;
			for(i=0; i<5 && s[i]!='\0'; i++)
				if(s[i]>'9' || s[i]<'0')
				{
					flag=0;
					break;
				}
			if(flag == 1)
			{
				*a = 0;
				for(i=0; i<5 && s[i]!='\0'; i++)
					*a = (*a)*10 + s[i] - '0';
				if(*a != 0)
					return;
			}
		}
		printf("Please give me a right int number which is smaller than 10000:\n");
	}
 } 
 
/* 获取一个属于(-10000,10000)的int数据 */
void getAllInt(int *a)
{
	char s[50];
	int flag=1;
	while(1)
	{
		gets(s);
		if(*s == '-')
		{
			if(strlen(s) < 6)
			{
				int i;
				for(i=1; i<6 && s[i]!='\0'; i++)
					if(s[i]<'0' || s[i]>'9');
					{
						flag = 0;
						break;
					}
				if(flag == 1)
				{
					*a = 0;
					for(i=1; i<6 && s[i]!='\0'; i++)
						*a = (*a)*10 + s[i] - '0';
					(*a) *= -1;
					return;
				}
			}
		}
		else if(strlen(s) < 5)
		{
			int i;
			for(i=0; i<5 && s[i]!='\0'; i++)
				if(s[i]<'0' || s[i]>'9')
				{
					flag = 0;
					break;
				}
			if(flag == 1)
			{
				*a = 0;
				for(i=0; i<5 && s[i]!='\0'; i++)
					*a = (*a)*10 + s[i] - '0';
				return;
			}
		}
		printf("Please give me a right int number which is bigger than -10000 and smaller than 10000;\n");
	}
}
