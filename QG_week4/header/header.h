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

void show();// �����溯�� 
void CreateBiTree(BiTree T);// ������  
void CreateTree(BiTree T, int depth, int *number, int min);//�������Ӻ��� 
void GetInt(int *a);//��ȡһ������0��int���� 
void ReadMain(BiTree T);//������������ 
void FReadBiTreeR(BiTree T);//ǰ��ݹ���� 
void BReadBiTreeR(BiTree T);//����ݹ���� 
void MReadBiTreeR(BiTree T);//����ݹ���� 
void FReadBiTree(BiTree T);//�ǵݹ�ǰ����� 
void BReadBiTree(BiTree T);//�ǵݹ������� 
void MReadBiTree(BiTree T);//�ǵݹ�������� 
void LReadBiTree(BiTree T);//������� 
int Depth(BiTree T);//�����������
int NodeCount(BiTree T);//���ؽ����
void NodeCount1(BiTree T, int *number);//���������Ӻ���
int LeafCount(BiTree T);//����Ҷ��
void LeafCount1(BiTree T, int *number);//����Ҷ���Ӻ��� 
void DeleteNode(BiTree T, int key);//ɾ����ֵΪkey���� 
BiTree SearchNode(BiTree T, int key);//������ֵΪkey�Ľ�㲢���� 
void AddNode(BiTree T, int key);//�����½�� 
void CheckTree(BiTree T, int n);//������Ƿ������������ 
int CheckRight(BiTree T, int n);//����Ӻ��� 
int CheckLeft(BiTree T, int n);//����Ӻ��� 
void ShowNode(BiTree T);//��ʾ���������Ϣ 
void DestroyTree(BiTree T);//������
