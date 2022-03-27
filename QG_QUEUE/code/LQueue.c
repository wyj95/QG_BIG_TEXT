#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "..\head\LQueue.h" 

extern char type;
extern char datatype[MAX_QUEUE];
				
/**
 *  @name          : void InitLQueue(LQueue *Q)
 *  @description   : 初始化队列
 *  @param         :  Q 队列指针Q
 *  @notice        : None
 */
void InitLQueue(LQueue *Q){
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name          : void DestoryLQueue(LQueue *Q)
 *  @description   : 销毁队列
 *  @param         : Q 队列指针Q
 *  @notice        : None
 */
void DestoryLQueue(LQueue *Q){
	ClearLQueue(Q);
	free(Q);
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->length == 0)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : 查看队头元素
 *  @param       : Q e 队列指针Q,返回数据指针e
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void **e){
	if(Q->length == 0)
		return FALSE;
	*e = Q->front->data;
	return TRUE;
}

/**
 *  @name          : Status LengthLQueue(LQueue *Q, int *length)
 *  @description   : 确定队列长度
 *  @param         : Q 队列指针Q,lenth 队列长度 
 *  @return        : 成功-TRUE; 失败-FALSE
 *  @notice        : None
 */
Status LengthLQueue(LQueue *Q,int *length){
	Node *p1;
	int truelength=0; /* 真正的队列长度 */ 
	p1 = Q->front;
	while(p1 != NULL)
	{
		p1 = p1->next;
		truelength++;
	}
	if( (*length=truelength) == Q->length )
		return TRUE;
	else
		return FALSE;
		
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q 队列指针Q,入队数据指针data
 *  @return      :成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	Node *p1=(Node*)malloc(sizeof(Node));
	if(p1 == NULL)
		return FALSE;
	p1->data = data;
	p1->next = NULL;
	if(Q->length == 0)
	{
		Q->rear = p1;
		Q->front = p1;
	}
	/*队列为空，队头和队尾都为新结点，否则直接将新结点连上去再置队尾为新结点 */ 
	else
	{
		Q->rear->next = p1;
		Q->rear = p1;
	}
	datatype[Q->length] = type;
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q, void **e)
 *  @description : 出队操作
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q, void **e){
	if(Q->front == NULL)
		return FALSE;
	*e = Q->front->data;
	Node *p1;
	p1 = Q->front->next;
	free(Q->front);
	/* 在外面访问完e指针后再free掉 */ 
	Q->front = p1;
	Q->length--;
	type = datatype[0];
	/* 记录该被删除的结点类型 */ 
	int i;
	for(i=0; i<Q->length; i++)
		datatype[i] = datatype[i+1];
	/* 队列数组依次前移 */ 
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : 清空队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	Node *p1=Q->front;
	while(p1 != NULL)
	{
		p1 = p1->next;
		free(Q->front->data);
		free(Q->front);
		Q->front = p1;
	}
	/* 遍历队列，依次free掉结点和数据指针 */ 
	Q->rear = NULL;
	Q->length = 0;
	/* 前结点已在上操作中变成NULL了 */ 
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *  @description : 遍历函数操作
 *  @param       : Q 队列指针Q，操作函数指针foo
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	if(Q->length == 0)
		return FALSE;
	Node *p1;
	p1 = Q->front;
	int i=0;
	while(p1 != NULL)
	{
		type = datatype[i++];
		printf("%d.", i);
		(*foo)(p1->data);
		p1 = p1->next;
	}
	/* 依次置type变量为当前结点数据类型，后调用函数访问 */ 
}

/**
 *  @name        : void LPrint(void *q)
 *  @description : 操作函数
 *  @param       : q 指针q
 *  @notice      : None
 */
void LPrint(void *q){
	if(type == 'i')
	{
		printf("%d\n", *( (int *)q ));
	}
	else if(type == 'c')
	{
		printf("%c\n", *( (char*)q ));
	}
	else if(type == 'f')
	{
		printf("%.2f\n", *( (float*)q ));
	}
	else if(type == 's')
	{
		printf("%s\n",  (char*)q );
	}
	/* 根据不同类型进行删除，在外部调用该函数前已将type置为q对应类型 */ 
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
