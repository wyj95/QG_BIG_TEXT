/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#define MAX_QUEUE 50
/**************************************************************
 *    Struct Define Section
 **************************************************************/
//链式队列结构
typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;         //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    int length;            //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;		

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void GetType()
 *  @description : 获取类型 
 *  @param       : None
 *  @notice      : None
 */
void GetType();

/**
 *  @name        : void GetData(void **data)
 *  @description : 根据type类型不同获取不同数据 
 *  @param       : data 待获取数据指针域（未分配，在对应GetInt等函数中分配 
 *  @notice      : 需先确定type 
 */
void GetData(void **data); 

/**
 *  @name        : void getInt(void ** data)
 *  @description : 获取int数据 
 *  @param       : data 数据待存储地址 
 *  @notice      : 分配地址给data且判断是否是正常int 
 */
void GetInt(void **data);

/**
 *  @name        : void getFloat(void ** data)
 *  @description : 获取float数据 
 *  @param       : data 数据待存储地址 
 *  @notice      : 分配地址给data且判断是否是正常float
 */
void GetFloat(void **data);

/**
 *  @name        : void getChar(void ** data)
 *  @description : 获取Char数据 
 *  @param       : data 数据待存储地址 
 *  @notice      : 分配地址给data
 */
void GetChar(void **data);

/**
 *  @name        : void getCharS(void ** data)
 *  @description : 获取字符串数据 
 *  @param       : data 数据待存储地址 
 *  @notice      : 分配地址给data
 */
void GetCharS(void **data);

/**
 *  @name        : void show()
 *  @description : 初始化后显示主界面和用户选择对应操作 
 *  @param       : None
 *  @notice      : None
 */
void Show();

/**
 *  @name          : void InitLQueue(LQueue *Q)
 *  @description   : 初始化队列
 *  @param         :  Q 队列指针Q
 *  @notice        : None
 */
void InitLQueue(LQueue *Q);

/**
 *  @name          : void DestoryLQueue(LQueue *Q)
 *  @description   : 销毁队列
 *  @param         : Q 队列指针Q
 *  @notice        : None
 */
void DestoryLQueue(LQueue *Q);

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : 检查队列是否为空
 *  @param       : Q 队列指针Q
 *  @return      : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q);

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : 查看队头元素
 *  @param       : Q e 队列指针Q,返回数据指针e
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void **e);

/**
 *  @name          : Status LengthLQueue(LQueue *Q, int *length)
 *  @description   : 确定队列长度
 *  @param         : Q 队列指针Q,lenth 队列长度 
 *  @return        : 成功-TRUE; 失败-FALSE
 *  @notice        : None
 */
Status LengthLQueue(LQueue *Q, int *length);

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *  @description : 入队操作
 *  @param       : Q 队列指针Q,入队数据指针data
 *  @return      :成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data);

/**
 *  @name        : Status DeLQueue(LQueue *Q, void **e)
 *  @description : 出队操作
 *  @param       : Q 队列指针Q
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q, void **e);

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *  @description : 清空队列
 *  @param       : Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q);

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *  @description : 遍历函数操作
 *  @param       : Q 队列指针Q，操作函数指针foo
 *  @return      : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));

/**
 *  @name        : void LPrint(void *q)
 *  @description : 操作函数
 *  @param       : q 指针q
 *  @notice      : None
 */
void LPrint(void *q);

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


