#include<stdio.h>
#include<stdlib.h>
#include"QG_dulist_header.h"


int main()
{
	DuLinkedList head;
	if(InitList_DuL(&head) == (Status)ERROF)
		return ERROF;
	int lenth, flag;
	int p_num=0, q_num=0;/* get p's and q's number */
	DuLinkedList p,q;
	DuLinkedList p1;
	int del_num;
	while(1)
	{
		lenth = 0;
		printf("Please give me the lenth of you Dulinkedlist:\n");
		scanf("%d", &lenth);
		if(lenth > 0)
		{
			printf("The Dulinkedlist has been created!\n");
			break;
		}
		else
			printf("Plaese give the right number!\n");
		
	}
	CreateList_DuL(head, lenth);
	while(1)
	{
		while(1)
		{
			flag = 0;
			printf("You can do these functions:\n");
			printf("1.Insert one node before another node;\n");
			printf("2.Insert one node after another node;\n");
			printf("3.delete one noed's next node;\n");
			printf("4.Read all the number of the list;\n");
			printf("5.Destroy the Dulinkedlist and quit.\n");
			printf("Now you can give me the number:\n");
			scanf("%d", &flag);
			if(flag>0 && flag<6)
				break;
			else
				printf("Please give me the right number!\n");
		}
		switch(flag)
		{
			case(1):
				while(1)
				{
					printf("Please give me a number which is smaller than %d and bigger than 0:\n", lenth);
					scanf("%d", &p_num);
					if(p_num>0 && p_num<=lenth)
						break;
					else
						printf("Please give me a number which is smaller than %d and biger than 0!\n");
				}
				printf("Now please me another number you want to insert before what you give me just now:\n");
				scanf("%d", &q_num); 
				DuLinkedList p,q;
				q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = q_num;
				p = head;
				for(int i=1; i<p_num; i++)
					p = p->next;
				InsertBeforeList_DuL(p,q);
				lenth++;
				break;
			case(2):
				while(1)
				{
					printf("Please give me a number which is smaller than %d and bigger than 0:\n", lenth);
					scanf("%d", &p_num);
					if(p_num>0 && p_num<=lenth)
						break;
					else
						printf("Please give me a number which is smaller than %d and biger than 0!\n");
				}
				printf("Now please me another number you want to insert after what you give me just now:\n");
				scanf("%d", &q_num); 
				q = (DuLinkedList)malloc(sizeof(DuLNode));
				q->data = q_num;
				p = head;
				for(int i=1; i<p_num; i++)
					p = p->next;
				InsertAfterList_DuL(p,q);
				lenth++;
				break;
			case(3):
				p_num=0;/* get p's number */
				while(1)
				{
					printf("Please give me a number which is smaller than %d and bigger than 0:\n", lenth);
					scanf("%d", &p_num);
					if(p_num>0 && p_num<=lenth)
						break;
					else
						printf("Please give me a number which is smaller than %d and biger than 0!\n", lenth);
				}
				p1 = head;
				for(int i=1; i<p_num; i++)
					p1 = p1->next;
				del_num=0;/* the number of the node deleted */
				if(DeleteList_DuL(p1, &del_num) == SUCCESS)
					printf("The number of the node deleted is %d.\n", del_num);
				else
					return ERROF;
				lenth--;
				break;
			case(4):
				ReadDuL(head);
				break;
			case(5):
				DestroyList_DuL(&head);
				return 0;
		}
	}
	return -1;
}

/**
 *  @name        : void ReadDuL(DuLinkedList *head)
 *	@description : read all the number of the list
 *	@param		 : head(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void ReadDuL(DuLinkedList head)
{
	DuLinkedList p1=head;
	int i=1;
	while(p1 != NULL)
	{
		printf("%d.%d\n", i++, p1->data);
		p1 = p1->next;
	}
}

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L)
{
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if(*L == NULL)
		return ERROF;
	(*L)->data = 0;
	(*L)->prior = NULL;
	(*L)->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void CreateList_DuL(DuLinkedList *L)
 *	@description : Create a linked list whose lenth is lenth
 *	@param		 : L(the head node) lenth
 *	@return		 : None
 *  @notice      : None
 */
void CreateList_DuL(DuLinkedList L, int lenth)
{
	L->data = lenth--;
	DuLinkedList p1,p2=L;
	while(lenth != 0)
	{
		p1 = (DuLinkedList)malloc(sizeof(DuLNode));
		p1->data = lenth--;
		p1->prior = p2;
		p2->next = p1;
		p2 = p1;
	}
	p1->next = NULL;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L)
{
	DuLinkedList p1,p2;
	p1 = *L;
	p2 = *L;
	while(p1 != NULL)
	{
		p1 = p2->next;
		free(p2);
		p2 = p1;
	}
	*L = NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
{

	q->prior = p->prior;
	if(p->prior != NULL)
		p->prior->next = q;
	q->next = p;
	p->prior = q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
{
	/* Maybe we can InsertBeforeList_DuL(DuLNode *q, DuLNode *p) */
	q->prior = p;
	if(p->next != NULL)
		p->next->prior = q;
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e)
{
	if(p->next == NULL)
		return ERROF;
	p->next = p->next->next;
	*e = p->next->prior->data;
	free(p->next->prior);
	p->next->prior = p;
	return SUCCESS;
}


