#include<sort.h>
/**
 *  @name        : void swap(int *a,int *b)
 *  @description : 交换ab的值 
 *  @param       : 待交换数指针a，b 
 */
void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

/**
 *  @name        : void ColorSortMain()
 *  @description : 颜色排序主函数 
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColourSortMain()
{
	long int length;
	printf("Please give me the length of the list:\n");
	GetLongInt(&length); 
	int *p=(int*)malloc(sizeof(int) * length);
	if(p == NULL)
	{
		printf("The room is full!");
		exit(0);
	}
	for(long int i=0; i<length; i++)
	{
		p[i] = rand() % 3;
	}
	printf("Before sorting,they are:\n");
	Sleep(3000);
	for(long int i=0; i<length; i++)
		printf("%d", p[i]);
	printf("\n");
	printf("Give me anything,I will sort it...");
	while(getchar() != '\n');
	ColourSort(p, length);
	printf("After sorting,they are:\n");
	Sleep(3000);
	for(long i=0; i<length; i++)
	{
		printf("%d", p[i]);
	}
	printf("\n");
	free(p);
}

/**
 *  @name        : void ColorSort(int *a,long int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColourSort(int *a,long int size)
{
	int *pbegin=a, *pend=a+size-1;
	long int i=-1;
	while(a+i++ < pend)
	{
		if(a[i] == 2)
		{
			a[i] = 1;
			*(pbegin++) = 2;
		}
		else if(a[i] == 0)
		{
			a[i] = 1;
			*(pend--) = 0;
		}
		/* 此处 a[i]=1 也可以等循环结束后从pbegin到pend依次赋值1 */ 
	}
}

/**
 *  @name        : int FindKthMain()
 *  @description : 找数主函数 
 *  @param       : None
 */
void FindKthMain()
{
	long int length, flag;
	printf("Please give me the length of the list:\n");
	GetLongInt(&length); 
	int *p=(int*)malloc(sizeof(int) * length);
	if(p == NULL)
	{
		printf("The room is full!");
		exit(0);
	}
	random_number(p, length);
	printf("Please give me the number th after sorting:\n");
	while(1)
	{
		flag = 0;
		GetLongInt(&flag);
		if(flag <= length)
			break;
		else
			printf("Please give me a number which is smaller than %ld", length);
	}
	printf("The %ld th number is %d\n", flag, FindKth(p, flag-1, 0, length-1));
}

/**
 *  @name        : int FindKth(int *a, int key, int begin, int end)
 *  @description : 在一个无序序列中找到第key大/小的数
 *  @param       : 数组指针a，目标序号key，key属于的区间(begin,end) 也即本次搜索范围 
 */
int FindKth(int *a, long int key, long int begin, long int end)
{
	long int i=begin, j=end;
	int t=a[i];
	while(i < j)
	{
		while(a[j]<t && j>i)
			j--;
		if(j > i)
			a[i++]=a[j];
		while(a[i]>t && j>i)
			i++;
		if(j > i)
			a[j--]=a[i];
	}
	a[i]=t;
	if(i>key)
		return FindKth(a, key, begin, i);
	else if(i<key)
		return FindKth(a, key, i+1, end);
	else
		return a[i];
	/* 根据不同取值结束操作或继续缩小区间，另外基于key一定在数组范围内，故不会出现end<begin情况 */ 
}


/**
 *  @name        : void random_number(int *p,long int size)
 *  @description : 随机生成size个数字存储于p中
 *  @param       : 数据指针p，数组大小size 
 */
void random_number(int *p,long int size)
{
	for(long int i=0; i<size; i++)
		p[i] = rand();
}
