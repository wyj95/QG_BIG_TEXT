#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h> 
#define max(x,y) x>y?x:y


typedef struct Tree
{
	int data;
	Tree *left, *right;
}*BiTree, Tree;
typedef struct Stack
{
	BiTree data;
	Stack *next;
}Stack;
Stack *TreeStack = NULL;
struct Queue
{
	Stack* head;
	Stack* now;
}*TreeQueue;

void show();// 主界面函数 
void CreateBiTree(BiTree T);// 建立树  
void CreateTree(BiTree T, int depth, int *number, int min);//建立树子函数 
void GetInt(int *a);//获取一个大于0的int数据 
void ReadMain(BiTree T);//遍历树主函数 
void FReadBiTreeR(BiTree T);//前序递归遍历 
void BReadBiTreeR(BiTree T);//后序递归遍历 
void MReadBiTreeR(BiTree T);//中序递归遍历 
void FReadBiTree(BiTree T);//非递归前序遍历 
void BReadBiTree(BiTree T);//非递归后序遍历 
void MReadBiTree(BiTree T);//非递归中序遍历 
void LReadBiTree(BiTree T);//层序遍历 
int Depth(BiTree T);//返回树的深度
int NodeCount(BiTree T);//返回结点数
void NodeCount1(BiTree T, int *number);//计算结点数子函数
int LeafCount(BiTree T);//返回叶数
void LeafCount1(BiTree T, int *number);//计算叶数子函数 
void DeleteNode(BiTree T, int key);//删除数值为key的数 
BiTree SearchNode(BiTree T, int key);//查找数值为key的结点并返回 
void AddNode(BiTree T, int key);//加入新结点 
void CheckTree(BiTree T, int n);//检查树是否是排序二叉树 
int CheckRight(BiTree T, int n);//检查子函数 
int CheckLeft(BiTree T, int n);//检查子函数 
void ShowNode(BiTree T);//显示该树相关信息 
void DestroyTree(BiTree T);//销毁树
