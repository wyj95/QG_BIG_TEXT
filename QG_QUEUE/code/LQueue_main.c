#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"..\head\LQueue.h"

char type;
char datatype[MAX_QUEUE];
/*
 * 本程序将使用datatype数组模拟队列存储泛型队列数据类型
 * 但是这样会使链式队列优点不明显
 * 所以要是可以选择的话把数据类型放在队列结点里效果应该会更好
 * （如果我没理解错datatype打开方式的话...）
 */ 

int main()
{
	Show();
	return 0;
}

/**
 *  @name        : void GetType()
 *  @description : 获取类型 
 *  @param       : None
 *  @notice      : None
 */
void GetType()
{
	while(1)
	{
		type = '\0';
		printf("Please give me what kind of the data you want to keep:\n");
		printf("'i' means int, 'f' means float, 'c' means char while 's' means char string!\n");
		scanf("%c", &type);
		while(getchar() != '\n');
		if(type=='i' || type=='f' || type=='c' || type=='s')
			break;
		else
		{
			system("cls");
			printf("Please don't give me others!\n");
		}
	}
}

/**
 *  @name        : void GetData(void **data)
 *  @description : 根据type类型不同获取不同数据 
 *  @param       : data 待获取数据指针域（未分配，在对应GetInt等函数中分配 
 *  @notice      : 需先确定type 
 */
void GetData(void **data)
{
	if(type == 'i')
	{
		GetInt(data);
	}
	else if(type == 'f')
	{
		GetFloat(data);
	}
	else if(type == 'c')
	{
		GetChar(data);
	}
	else if(type == 's')
	{
		GetCharS(data);
	}
}

/**
 *  @name        : void getInt(void ** data)
 *  @description : 获取int数据 
 *  @param       : data 数据待存储地址 
 *  @notice      : 分配地址给data且判断是否是正常int 
 */
void GetInt(void **data)
{
	printf("Please give me a int number:\n");
	int *p = (int*)malloc(sizeof(int));
	/* 此为实际地址 */ 
	char s[10];  /* 存储待转化目标字符串 */ 
	int i;       /* 用于循环 */ 
	int flag;    /* 用于判断有无异常字符出现  flag==1 正常   flag==0 有其他字符出现*/ 
	while(1)
	{
		for(i=0; i<10 && (s[i]=getchar()) != '\n'; i++);
		if(i == 10)
		{
			*s = 'X';/* 直接跳过判断 */ 
			while(getchar() != '\n');
		}
		else
			s[i] = '\0';
		flag = 1;
		if(*s == '-')
		{
			/* 限制实际数字应该小于10000，不用系统int数据大小不一定一样 */ 
			if(strlen(s) < 6)
			{
				for(i=1; i<6 && s[i]!='\0'; i++)
					if(s[i]<'0' || s[i]>'9')
					{
						flag = 0;
						break;
					}/* 出现异常字符 */ 
				if(flag == 1)
				{
					*p = 0;
					for(i=1; i<6 && s[i]!='\0'; i++)
						*p = (*p)*10 + s[i] - '0';
					(*p) *= -1;
					*data = (void*)p;
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
				*p = 0;
				for(i=0; i<5 && s[i]!='\0'; i++)
					*p = (*p)*10 + s[i] - '0';
				*data = (void*)p;
				return;
			}
		}
		printf("Please give me a right int number which is bigger than -10000 and smaller than 10000;\n");
	}	
}

/**
 *  @name        : void getFloat(void ** data)
 *  @description : 获取float数据 
 *  @param       : data 数据待存储地址 
 *  @notice      : 分配地址给data且判断是否是正常float
 */
void GetFloat(void **data)
{
	printf("Please give me a float number:\n");
	int length[2]; /* 用于统计整数部分length[0]和小数部分长度length[1] */ 
	int flag;      /* 用于判断字符串是否有其他奇奇怪怪的玩意（是：flag==0） */ 
	int status;    /* 用于判断此时遍历的数组是在小数点前还是小数点后 */ 
	char s[20];    /* 待转化成float的目标字符串 */ 
	float count;   /* 用于协助计算小数部分 */ 
	float *p;      /* 存储float型数据 */ 
	p = (float*)malloc(sizeof(float));
	while(1)
	{
		int i;
		for(i=0; i<20 && (s[i]=getchar()) != '\n'; i++);
		if(i == 20)
		{
			while(getchar() != '\n');
			system("cls");
			printf("Please don't give me something else,\n");
			printf("And the part bigger than 1 of the number you give shouldn't be longer than 4,");
			printf("as well as the part smaller than 1!\n");
			continue;
		}
		else
			s[i] = '\0';
		/* 以上，防止数组越界 */ 
		flag = 1;
		status = 0;
		length[0] = 0;
		length[1] = 0;
		i=0;
		if(*s == '-')
		{
			i++;
			while(s[i]!='\0')
			{
				if(s[i]>='0' && s[i]<='9')
					length[status] ++;
				else if(s[i]=='.' && status==0)
				{
					status = 1;
				}
				else
				{
					flag = 0;
					break;
				}
				i++;
			}
			if(length[0]>4 || length[1]>4)
				flag = 0;
			if(flag == 1)
			{
				count = 0.1;
				*p = 0.0;
				for(i=0; s[i]!='.' && s[i]!='\0'; i++)
					*p = (*p)*10 + s[i] - '0';
				if(s[i] == '.')
					i++;
				for(; s[i]!='\0'; count /= 10)
					*p += count * (s[i++]-'0');
				*p *= -1;
				*data = (void*)p;
				return;
			}
		}
		else
		{
			while(s[i]!='\0')
			{
				if(s[i]>='0' && s[i]<='9')
					length[status] ++;
				else if(s[i]=='.' && status==0)
				{
					status = 1;
				}
				else
				{
					flag = 0;
					break;
				}
				i++;
			}
			if(length[0]>4 || length[1]>4)
				flag = 0;
			if(flag == 1)
			{
				count = 0.1;
				*p = 0.0;
				for(i=0; s[i]!='.' && s[i]!='\0'; i++)
					*p = (*p)*10 + s[i] - '0';
				if(s[i] == '.')
					i++;
				for(; s[i]!='\0'; count /= 10)
					*p += count * (s[i++]-'0');
				*data = (void*)p;
				return;
			}
		}
		system("cls");
		printf("Please don't give me something else,\n");
		printf("And the part bigger than 1 of the number you give shouldn't be longer than 4,");
		printf("as well as the part smaller than 1!\n");
	}
}

/**
 *  @name        : void getCharS(void ** data)
 *  @description : 获取字符串数据 
 *  @param       : data 数据待存储地址 
 *  @notice      : 分配地址给data
 */
void GetCharS(void **data)
{
	printf("Please give me a char string whose length is shorter than 50:\n"); 
	char *p=(char*)malloc(sizeof(char)*50);
	int i;
	for(i=0; i<50 && (p[i]=getchar()) != '\n'; i++);
	if(i==50)
	{
		p[49] = '\0';
		while(getchar() != '\n');
	}
	else
		p[i] = '\0';
	/* 防止数组越界 */ 
	*data = (void*)p;
}

/**
 *  @name        : void getChar(void ** data)
 *  @description : 获取Char数据 
 *  @param       : data 数据待存储地址 
 *  @notice      : 分配地址给data
 */
void GetChar(void **data)
{
	printf("Please give me one char.\nIf you give me more,I will get the first:\n");
	char *p = (char*)malloc(sizeof(char));
	/* 一定程度上防止输入过长程序奔溃 */
	*p = getchar();
	if(*p == '\n')
		*p = '0';/* 防止奇奇怪怪的换行，观感不好 */ 
	while(getchar() != '\n');
	*data = (void*)(p);
}

/**
 *  @name        : void show()
 *  @description : 初始化后显示主界面和用户选择对应操作 
 *  @param       : None
 *  @notice      : None
 */
void Show()
{
	LQueue* Q=(LQueue*)malloc(sizeof(LQueue));    /* 队列 */ 
	void *data;                                   /* 用于收集数据 */ 
	void *addData;                                /* 用于添加结点时分配地址相关操作 */ 
	int flag;                                     /* 判断用户操作 */ 
	int length;                                   /* 数组长度 */ 
	InitLQueue(Q);/* 初始化队列 */ 
	while(1)
	{
		while(1)
		{
			flag = 0;
			printf("You can do these function:\n");
			printf("1.Check whether the queue is empty or not;\n");
			printf("2.Get the data of the queue head;\n");
			printf("3.Add a node into the queue;\n");
			printf("4.Get a node out of the queue;\n");
			printf("5.Read all the node of the queue;\n");
			printf("6.Get the length of the queue;\n");
			printf("7.Delete the queue;\n");
			printf("8.Quit.\n");
			printf("Now please give me the number to finish the function:\n");
			scanf("%d", &flag);
			while(getchar() != '\n');
			if(flag<1 || flag>8)
			{
				system("cls");
				printf("Please give me the right number!");
			}
			else
				break;
		}
		switch(flag)
		{
			case(1):
				if(IsEmptyLQueue(Q) == TRUE)
					printf("The queue is empty now!You should add something!\n");
				else
					printf("The queue is not empty now.\n");
				break;
			case(2):
				if(GetHeadLQueue(Q, &data) == TRUE)
				{
					type = datatype[0];
					/* 获取队头数据类型 */ 
					LPrint(data);
				}
				else
					printf("The queue is empty now!You should add something!\n");
				break;
			case(3):
				if(Q->length > MAX_QUEUE-1)
				{
					printf("Sorry,but the stack is full!\n");
					break;
				}
				/* 防止datatype数组越界 */ 
				GetType();
				GetData(&addData);
				/* 先获取数据类型 再在GetData调用的对应getInt等函数里分配地址 */ 
				if(EnLQueue(Q, addData) == TRUE)
					printf("We have add it into the queue!\n");
				else
				{
					printf("The room is full!!!\n");
					exit(-1);
				}
				break;
			case(4):
				if(DeLQueue(Q, &data) == TRUE)
				{
					printf("We have get the node out of the queue.\n");
					printf("And it is :");
					/* 已在 DeLQueue函数中获取删除结点的type */
					LPrint(data);
					free(data);
					/* 输出完就将他删除 */ 
				}
				else
					printf("The queue is empty now!\n");
				break;
			case(5):
				printf("They are:\n");
				TraverseLQueue(Q, LPrint);
				break;
			case(6):
				if(LengthLQueue(Q, &length) == TRUE)
					printf("The length of the queue is %d.\n", length);
				else
				{
					printf("There is some wrong in the queue!!!\n");
					exit(-1);
				}
				break;
			case(7):
				ClearLQueue(Q);
				break;
			case(8):
				DestoryLQueue(Q);
				return;
		}
		printf("Please give me anything to continue:\n");
		while(getchar() != '\n');
		system("cls");
	}
}
