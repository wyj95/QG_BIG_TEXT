#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#define BEGIN begin=clock()
#define END end=clock()

/**
 *  @name        : void InsertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void InsertSort(int *a, long int n);

/**
 *  @name        : void MergeArray(int *a,int begin,int end);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void MergeArray(int *a,long int begin,long int end);

/**
 *  @name        : void MergeSort(int *a,int begin,int end);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void MergeSort(int *a,long int begin,long int end);

/**
 *  @name        : void QuickSortRecursion(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSortRecursion(int *a, long int begin, long int end);


/**
 *  @name        : void QuickSort(int *a,long int begin, long int end)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,long int begin, long int end);

/**
 *  @name        : long int Partition(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
long int Partition(int *a, long int begin, long int end);


/**
 *  @name        : void CountSort(int *a, int size)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size
 */
void CountSort(int *a, long int size);
 
/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,long int size);

/**
 *  @name        : void swap(int *a,int *b)
 *  @description : 交换ab的值 
 *  @param       : 待交换数指针a，b 
 */
void swap(int *a, int *b);

/**
 *  @name        : void ColorSortMain()
 *  @description : 颜色排序主函数 
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColourSortMain();

/**
 *  @name        : void ColorSort(int *a,long int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColourSort(int *a,long int size);

/**
 *  @name        : int FindKthMain()
 *  @description : 找数主函数 
 *  @param       : None
 */
void FindKthMain();

/**
 *  @name        : int FindKth(int *a, int key, int begin, int end)
 *  @description : 在一个无序序列中找到第key大/小的数
 *  @param       : 数组指针a，目标序号key，key属于的区间(begin,end) 也即本次搜索范围 
 */
int FindKth(int *a, long int key, long int begin, long int end);


/**
 *  @name        : void random_number(int *p,long int size)
 *  @description : 随机生成size个数字存储于p中
 *  @param       : 数据指针p，数组大小size 
 */
void random_number(int *p,long int size);

/**
 *  @name        : void TestBigData(long int size)
 *  @description : 对各个排序算法进行长数组测试 
 *  @param       : 数组大小size 
 */
void TextBigData(long int size);

/**
 *  @name        : void TestLittleData()
 *  @description : 对各个排序算法进行多次(1e5)短数组(100)测试 
 *  @param       : None
 */
void TextLittleData();

/**
 *  @name        : void text_sort()
 *  @description : 对所有排序进行一次并检验正确与否 
 *  @param       : None
 */
void TextSort();

/**
 *  @name        : void ReadFile()
 *  @description : 从文件中读入数据并排序后放回去 
 *  @param       : None
 */
void ReadFile();

/**
 *  @name        : void WriteFile()
 *  @description : 将生成的数组排序后放入文件 
 *  @param       : None
 */
void WriteFile();

/**
 *  @name        : void WriteRandFile()
 *  @description : 写入随机数 
 *  @param       : None
 */
void WriteRandFile();

/**
 *  @name        : void GetLongInt(long int *a)
 *  @description : 获取一个小于1000 000 大于0 的数 
 *  @param       : a (待获取数的地址) 
 */
void GetLongInt(long int *a);

/**
 *  @name        : void show()
 *  @description : 主界面 
 *  @param       : None 
 */
void Show();
