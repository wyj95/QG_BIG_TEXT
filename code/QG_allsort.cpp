#include<sort.h>
/**
 *  @name        : void InsertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void InsertSort(int *a, long int n)
{
	for(long int i=0; i<n-1; i++)
	{
		int max=a[i],cj=i;/* cj记录最大值对应的位置 */ 
		for(int j=i; j<n; j++)
			if(a[j] > max)
			{
				cj = j;
				max = a[j];
			}
		int t = a[cj];/* 记录该点 */
		/* 以下实现插入操作 */
		for(long int j=cj; j>i; j--)
			a[j] = a[j-1];
		a[i] = t;
	}
}

/**
 *  @name        : void MergeArray(int *a,int begin,int end);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void MergeArray(int *a,long int begin,long int end)
{
	if(begin >= end)
		return;
	long int mid=end + begin;
	mid /= 2;                                           /* 中点 */
	int *p=(int *)malloc(sizeof(int)*(end - begin + 1));/* 存放数据 */
	long int b=begin, e=mid+1;							/* b从begin处游走向mid，e从mid处游走向end */ 
	long int i=0;                                       /* 用于辅助p记录数据 */
	while(b<=mid && e<=end)
	{
		if(a[b] < a[e])
			*(p + i++)=a[ e++];
		else
			*(p + i++)=a[ b++];
	}
	/* 逐个比较入数组p */ 
	while(b <= mid)
		*(p + i++)=a[ b++];
	while(e <= end)
		*(p + i++)=a[ e++];
	/* 清空余下的元素 */ 
	for(long int j=0; j<i; )
		a[begin + j] = *(p + j++);
	free(p);
	/* 将数组内元素拿出来后释放p */ 
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void MergeSort(int *a,long int begin,long int end)
{
	if(begin >= end)
		return;
	long int mid=end + begin;
	mid /= 2;
	MergeSort(a, begin, mid);
	MergeSort(a, mid+1, end);
	MergeArray(a, begin, end);
	/* 先归后并 */ 
}


/**
 *  @name        : void QuickSortRecursion(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSortRecursion(int *a, long int begin, long int end)
{
	if(begin >= end)
		return;
	long int i=begin, j=end;
	/* i用于从开头遍历，j用于从末尾开始遍历 */
	int t=a[i];/* 存储数组首元素 */ 
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
	a[i] = t;
	QuickSortRecursion(a, begin, i-1);
	QuickSortRecursion(a, i+1, end);
	/* 此时i应该等于j，故也可用j */ 
}


/**
 *  @name        : void QuickSort(int *a,long int begin, long int end)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,long int begin, long int end)
{
	long int partition;
	if(begin >= end)
		return;
	while(begin < end)
	{
		partition = Partition(a, begin, end);
		QuickSort(a, begin, partition-1);
		begin = partition+1;
	}
}


/**
 *  @name        : long int Partition(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
long int Partition(int *a, long int begin, long int end)
{
	long int i=begin, j=end;	/* i用于从开头遍历，j用于从末尾开始遍历 */
	int t=a[i];					/* 存储数组首元素 */ 
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
	a[i] = t;
	return i;
	/* 返回枢轴 */ 
}


/**
 *  @name        : void CountSort(int *a, int size)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size
 */
void CountSort(int *a, long int size)
{
	int max=a[0], min=a[0];
	long int i,j;
	for(i=1; i<size; i++)
		if(a[i] < min)
			min = a[i];
		else if(a[i] > max)
			max = a[i];
	int length=max - min + 1;
	/* 求出max和min后确立计数数组长度 */ 
	int *p=(int *)calloc(length, sizeof(int));
	/* 用于存储计数并默认置0 */ 
	for(i=0; i<size; i++)
		*(p + a[i] - min) += 1;
	j = 0;
	for(i=length-1; i>=0; i--)
		while(*(p+i) != 0)
		{
			*(p+i) -= 1;
			a[j++] = i+min;
		}
	/* 从计数数组中读出数据 */ 
	free(p);
}
 
/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,long int size)
{
	long int count1=10,count2=1;
	/* 用于计算对应位数 如 98%count1 / count2 == 8 得出count2对应的位数 */
	int max, min, temp;
	int *p[10];
	/* 10个桶 */ 
	for(int i=0; i<10; i++)
		p[i] = (int*)calloc(size, sizeof(int));
	long int number[10] = {0};
	/* p[10]用于计数各个桶数的数量 */ 
	while(count1 <= 100000) /*此处循环条件也可根据数组内不同数据大小修改或在下面的循环遍历时判断 */ 
	{
		for(long int i=0; i<size; i++)
		{
			temp = (int)(a[i]%count1 / count2);
			/* 得出该数属于那个桶（temp） */ 
			p[temp][ number[temp]++ ] = a[i];
			/* 插入该数 */
		}
		temp = 0;
		long int k = 0;/* 辅助a从桶中取出数据 */ 
		for(int i=9; i >= 0; i--)
		{
			for(long int j=0; j<number[i]; j++)
			{
				a[k++] = p[i][j];
			}
			number[i] = 0;
		}
		/* 出桶 */ 
		count1 *= 10;
		count2 *= 10; 
	}
	for(int i=0; i<10; i++)
		free(p[i]);
}


