#include<sort.h>
/**
 *  @name        : void TestBigData(long int size)
 *  @description : 对各个排序算法进行长数组测试 
 *  @param       : 数组大小size 
 */
void TextBigData(long int size)
{
	int *p = (int*)malloc(sizeof(int)*size);
	if(p == NULL)
	{
		printf("The room is full!");
		exit(0);
	}
	random_number(p, size);
	printf("Sort %ld numbers:\n", size);
	clock_t begin, end;
	BEGIN;
	InsertSort(p, size);
	END;
	printf("Insert_sort useing time      :%6.3f s\n", (float)(end-begin)/CLK_TCK);
	random_number(p, size);
	BEGIN;
	MergeSort(p, 0, size-1);
	END;
	printf("Merge sort using time        :%6.3f s\n", (float)(end-begin)/CLK_TCK);
	random_number(p, size);
	BEGIN;
	QuickSortRecursion(p, 0, size-1);
	END;
	printf("Quick sort using time        :%6.3f s\n", (float)(end-begin)/CLK_TCK);
	random_number(p, size);
	BEGIN;
	CountSort(p, size);
	END;
	printf("Count sort using time        :%6.3f s\n", (float)(end-begin)/CLK_TCK);
	random_number(p, size); 
	BEGIN;
	RadixCountSort(p, size);
	END;
	printf("Radix count sort using time  :%6.3f s\n", (float)(end-begin)/CLK_TCK);
	free(p);
}

/**
 *  @name        : void TestLittleData()
 *  @description : 对各个排序算法进行多次(1e5)短数组(100)测试 
 *  @param       : None
 */
void TextLittleData()
{
	long int size=100;
	/* size取long型为了适应其他函数 */ 
	int *p = (int*)malloc(sizeof(int)*size);
	clock_t begin, end, rand_lose;
	/* 每次计时时需减去循环带来的损失（rand_lose) */ 
	long int i;
	BEGIN;
	for(i=0; i<100000; i++)
		random_number(p, size);
	END;
	rand_lose = end - begin;
	printf("Sort 100 numbers  100 000  times:\n");
	BEGIN;
	for(i=0; i<100000; i++)
	{
		random_number(p, size);
		InsertSort(p, size);
	}
	END;
	printf("Insert_sort useing time      :%6.3f s\n", (float)(end-begin-rand_lose)/CLK_TCK);
	BEGIN;
	for(i=0; i<100000; i++)
	{
		random_number(p, size);
		MergeSort(p, 0, size-1);
	}
	END;
	printf("Merge sort using time        :%6.3f s\n", (float)(end-begin-rand_lose)/CLK_TCK);
	BEGIN;
	for(i=0; i<100000; i++)
	{
		random_number(p, size);
		QuickSortRecursion(p, 0, size-1);
	}
	END;
	printf("Quick sort using time        :%6.3f s\n", (float)(end-begin-rand_lose)/CLK_TCK);
	BEGIN;
	for(i=0; i<100000; i++)
	{
		random_number(p, size);
		CountSort(p, size);
	}
	END; 
	printf("Count sort using time        :%6.3f s\n", (float)(end-begin-rand_lose)/CLK_TCK);
	BEGIN;
	for(i=0; i<100000; i++)
	{
		random_number(p, size);
		RadixCountSort(p, size);
	}
	END;
	printf("Radix count sort using time  :%6.3f s\n", (float)(end-begin-rand_lose)/CLK_TCK);
	free(p);
}

/**
 *  @name        : void text_sort()
 *  @description : 对所有排序进行一次并检验正确与否 
 *  @param       : None
 */
void TextSort()
{
	int *p=(int*)malloc(sizeof(int)*1000);
	random_number(p, 1000);
	InsertSort(p, 1000);
	for(int i=0; i<999; i++)
		if(p[i] < p[i+1])
		{
			printf("There something wrong in insert sort!\n");
			exit(0);
		}
	printf("Insert sorting is right!\n");
	random_number(p, 1000);
	MergeSort(p, 0, 999);
	for(int i=0; i<999; i++)
		if(p[i] < p[i+1])
		{
			printf("There something wrong in merge sort!\n");
			exit(0);
		}
	printf("Merge sorting is right!\n");
	random_number(p, 1000);
	QuickSortRecursion(p, 0, 999);
	for(int i=0; i<999; i++)
		if(p[i] < p[i+1])
		{
			printf("There something wrong in QuickSortRecursion!\n");
			exit(0);
		}
	printf("QuickSortRecursion is right!\n");
	random_number(p, 1000);
	QuickSort(p, 0, 1000);
	for(int i=0; i<999; i++)
		if(p[i] < p[i+1])
		{
			printf("There something wrong in Quick sort!\n");
			for(int i=0; i<1000; i++)
				printf("%d\t", p[i]);
			exit(0);
		}
	printf("Quick sorting is right!\n");
	random_number(p, 1000);
	CountSort(p, 1000);
	for(int i=0; i<999; i++)
		if(p[i] < p[i+1])
		{
			printf("There something wrong in count sort!\n");
			exit(0);
		}
	printf("Count sorting is right!\n");
	random_number(p, 1000);
	RadixCountSort(p, 1000);
	for(int i=0; i<999; i++)
		if(p[i] < p[i+1])
		{
			printf("There something wrong in RadixCountSort!\n");
			exit(0);
		}
	printf("RadixCountSort is right!\n");
	free(p);
	 
}

/**
 *  @name        : void ReadFile()
 *  @description : 从文件中读入数据并排序后放回去 
 *  @param       : None
 */
void ReadFile()
{
	FILE *fp = fopen("file.txt", "rb");
	if(fp == NULL)
	{
		printf("Can not open the file!");
		return ;
	}
	long int length=0;
	fread(&length, sizeof(long int), 1, fp);
	if(length==0)
	{
		printf("There are not any numbers in the file!\n");
		return ;
	}
	int *p = (int*)malloc(sizeof(int) * length);
	fread(p, sizeof(int), length, fp);
	fclose(fp);
	QuickSortRecursion(p, 0, length);
	printf("Sorting has been finished.\n");
	printf("Could you like to see them?\nIf yes give me a '1':\n");
	if(getchar() == '1')
	{
		printf("They are:\n");
		for(long int i=0; i<length; i++)
		{
			if(i % 7 == 0)
				printf("\n");
			printf("%8ld.%5d\t", i,p[i]);
		}
	}
	while(getchar() != '\n');
	printf("\nNow I will try to write it into the file.\n");
	fp = fopen("file.txt", "wb");
	if(fp == NULL)
	{
		printf("Can not open the file!");
		return ;
	}
	fwrite(&length, sizeof(long int), 1, fp);
	fwrite(p, sizeof(int), length, fp);
	fclose(fp);
	printf("I have wrote they into the file!\n");
	free(p);
}

/**
 *  @name        : void WriteFile()
 *  @description : 将生成的数组排序后放入文件 
 *  @param       : None
 */
void WriteFile()
{
	long int length;
	FILE *fp;
	printf("Please give me the length of the list:\n");
	GetLongInt(&length); 
	int *p=(int*)calloc(length, sizeof(int));
	if(p == NULL)
	{
		printf("The room is full!");
		exit(0);
	}
	random_number(p, length);
	QuickSortRecursion(p, 0, length-1);
	printf("Could you like to see them?\nIf yes give me a '1':\n");
	if(getchar() == '1')
	{
		printf("They are:\n");
		for(long int i=0; i<length; i++)
		{
			if(i % 7 == 0)
				printf("\n");
			printf("%8ld.%5d\t", i,p[i]);
		}
	}
	while(getchar() != '\n');
	fp = fopen("file.txt", "wb");
	fwrite(&length, sizeof(long int), 1, fp);
	fwrite(p, sizeof(int), length, fp);
	fclose(fp);
	printf("\nI have write they into the file!\n");
	free(p); 
}

/**
 *  @name        : void WriteRandFile()
 *  @description : 写入随机数 
 *  @param       : None
 */
void WriteRandFile()
{
	long int length;
	FILE *fp;
	printf("Please give me the length of the list:\n");
	GetLongInt(&length); 
	int *p=(int*)malloc(sizeof(int) * length);
	if(p == NULL)
	{
		printf("The room is full!");
		exit(0);
	}
	random_number(p, length);
	fp = fopen("file.txt", "wb");
	fwrite(&length, sizeof(long int), 1, fp);
	fwrite(p, sizeof(int), length, fp);
	fclose(fp);
	printf("I have write they into the file!\n");
	free(p);
}

/**
 *  @name        : void GetLongInt(long int *a)
 *  @description : 获取一个小于1000 000 大于0 的数 
 *  @param       : a (待获取数的地址) 
 */
void GetLongInt(long int *a)
{
	char s[100];
	int flag=1;
	while(1)
	{
		gets(s);
		if(strlen(s) < 8)
		{
			int i;
			flag = 1;
			for(i=0; i<8 && s[i]!='\0'; i++)
				if(s[i]<'0' || s[i]>'9')
				{
					flag = 0;
					break;
				}
			if(flag == 1)
			{
				*a = 0;
				for(i=0; i<8 && s[i]!='\0'; i++)
					*a = (*a)*10 + s[i] - '0';
				if(*a != 0)
					return;
			}
		}
		printf("Please give me a right int number which is bigger than 0 and smaller than 1000 000;\n");
	}
}
