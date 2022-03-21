#include<stdio.h>
#include<stdlib.h>
#include"QG_list_header.h"

/*
 *These are fit anywhere in this file:
 *	All the params named p1,p2... are used to read whole the list
 *	All the param named flag is used to be given by user to finish the function
 *	All the params named i,j are used to count in the circulation
 *	All the param named lenth is the lenth of the list
 *	All the param named head is the head of the list
 */

/**
 *  @name        : int main()
 *	@description : user choise the function to finish it
 *	@param		 : none
 *	@return		 : 0 means normal quit
                   -1 means something wrong in the function about ring
                   -2 means quit without destroying the list
 *  @notice      : none
 */
int main()
{
	int flag=0;
	int lenth;
	list_t* head=create_list(&lenth);
	printf("The list has been built!\n");
	int p_num=0, q_num=0;/* get p's and q's number */
	int find_num;
	int del_num;
	list_t *p1,*p2;
	while(1)
	{
		flag = 0;
		printf("\nYou can give me these number to finish the function:\n");
		printf("1.Read all the number in the list;\n");
		printf("2.Change the even number node and the old number node;\n");
		printf("3.Find the mid number node of the list;\n");
		printf("4.Create a ring in the list;\n");
		printf("5.Check whether there is a ring in thr list or not;\n");
		printf("6.Reverse all the node in the list;\n");
		printf("7.Insert a node after another node;\n");
		printf("8.Search one node depending on the number you give;\n");
		printf("9.delete a node's next node;\n");
		printf("10.Destroy the list and quit.\n");
		printf("Now please give me the number to finish the function:\n");
		scanf("%d", &flag);
		if(flag<0 || flag>10)
		{
			printf("Please give me the right number!\n");
		}
		else
		{
			switch(flag)
			{
				case(1):
					read_list(head);
					break;
				case(2):
					head = change(head);
					break;
				case(3):
					find_mid(head);
					break;
				case(4):
					create_ring(head);
					flag = 0;
					/* Before destroying the ring,there are no way to do something else! */
					while(1)
					{
						printf("Now you can check whether if there is a ring in the list.\n");
						printf("You can give me a '1' to destroy the ring after checking,");
						printf("other is to only check!:\n");
						scanf("%d", &flag);
						if(flag == 1)
						{
							check_and_destroy_ring(head);
							printf("The ring has been destroy!\n");
							break;
						}
						else
						{
							
							if(check_ring(head) == 1)
							{
								printf("There really is a ring in the list!\n");
							}	
							else
							{
								printf("There is not a ring in the list!\n");
								return -1;
							}
						}
					}
					break;
				case(5):
					if(check_ring(head) != 1)
					{
						printf("There is not a ring in the list.\n");
					}
					else
					{
						printf("There is a ring in the list.\n");
						return -1;
					}
					break;
				case(6):
					head = reverse(head);
					read_list(head);
					p1 = head->next;
					head->next = NULL;
					head = reverse_recursion(head, p1);
					break;
				case(7):
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
					list_t *p, *q;
					q = (list_t*)malloc(sizeof(list_t));
					q->data = q_num;
					p = head;
					for(int i=1; i<p_num; i++)
						p = p->next;
					insert_list(p,q);
					lenth++;
					break;
				case(8):
					printf("Please give me the number what you want to find:\n");
					scanf("%d", &find_num);
					if(search_list(head, find_num) == 1)
						printf("We have found it in the list.\n");
					else
						printf("Sorry,we have not found it in the list.\n");
					break;
				case(9):
					p1=head;
					while(1)
					{
						printf("Please give me the number of the node whose next node is what you want to delete:\n");
						scanf("%d", &del_num);
						if(search_list(head, del_num) == 1)
							break;
						else
							printf("There is no node whose number is %d,please give a new one.\n", del_num);
					}
					while(p1->data != del_num)
						p1 = p1->next;
					if(delete_node(p1, &del_num) == 1)
						printf("The number of node deleted is %d.\n", del_num);
					break;
				case(10):
					destroy_list(head);
					return 0;
			}
		}
	}
	return -2;
}

/**
 *  @name        : list_t* create_list(int* lenth)
 *	@description : create a list
 *	@param		 : lenth
 *	@return		 : the head of the list
 *  @notice      : need user order the lenth of the list
                   we order three ways to create a list
 */
list_t* create_list(int *lenth)
{
	int flag=0;
	*lenth = 0;
	list_t *head = (list_t*)malloc(sizeof(list_t));
	list_t *p1,*p2;
	head->next == NULL;
	while(1)
	{
		printf("Now Please give me the lenth of the list you want to create:\n");
		scanf("%d", lenth);
		if(*lenth > 0)
			break;
		else
			printf("Please give me the right number!\n");
	}
	while(1)
	{
		printf("How would you like to create the list?\n");
		printf("1.Random something;\n2.Some numbers like \"4,3,2,1\";\n3.You give me some numbers.\n");
		printf("Now please give me the number:\n");
		scanf("%d", &flag);
		if(flag==1 || flag==2 || flag==3)
			break;
		else
		{
			printf("Please give me the right number!\n");
		}
	}
	if(flag == 2)
	{
		int i=*lenth;
		head->data = i;
		p1 = head;
		while(--i != 0)
		{
			p2 = (list_t*)malloc(sizeof(list_t));
			p2->data = i;
			p1->next = p2;
			p1 = p2;
		}
		p1->next = NULL;
		return head;
	}
	else if(flag == 3)
	{
		int a;
		printf("Now please give me the numbers:\n");
		int i=2;
		p1 = head;
		printf("1.");
		scanf("%d", &(head->data));
		while(i <= *lenth)
		{
			p2 = (list_t*)malloc(sizeof(list_t));
			printf("%d.", i++);
			scanf("%d", &(p2->data));
			p1->next = p2;
			p1 = p2;
		}
		p1->next = NULL;
		return head;
	}
	else
	{
		p1 = head;
		p1->data = rand()%1000;
		for(int i=1; i<*lenth; i++)
		{
			p2 = (list_t*)malloc(sizeof(list_t));
			p2->data = rand()%1000;
			p1->next = p2;
			p1 = p2;
		}
		p1->next = NULL;
		return head;
	}
}

/**
 *  @name        : void read_list(list_t* head)
 *	@description : print the number of all nodes of the list
 *	@param		 : head(the head of the list)
 *	@return		 : none
 *  @notice      : none
 */
void read_list(list_t* head)
{
	int i=1;
	while(head != NULL)
	{
		printf("%-2d.%d\n", i++, head->data);
		head = head->next;
	}
}

/**
 *  @name        : void change(list_t *head)
 *	@description : change the even number node and the old number node
 *	@param		 : head(the head of the list)
 *	@return		 : none
 *  @notice      : the p among them is: p1->XX1->p2->XX2->...,and XX1 and p2 is what we should change,then:
                   p1->next(XX1)->next = p2->next(XX2);
                   p2->next = p1->next(XX1);
				   p1->next = p2;
				   become: p1->p2->XX1->XX2->...
 */
list_t* change(list_t* head)
{
	list_t *p1,*p2;
	p1 = head;
	p2 = p1->next;
	if(p2 != NULL)
		p2 = p2->next;
	else
		return head;/* only one node,no need to change*/
	/*  now  : p1(head)->XX->p2->... */
	head = p1->next;
	head->next = p1;
	p1->next = p2;
	/* become: XX(head)->p1->p2->... */
	if(p2 != NULL)
		p2 = p2->next;
	/* head->p1->XX1->p2->XX2->...  we want XX1<->p2 */
	while(p2 != NULL)
	{
		p1->next->next = p2->next;
		p2->next = p1->next;
		p1->next = p2;
		/* p1->p2->XX1->XX2->... */
		p1 = p2->next;
		p2 = p1->next;
		if(p2 != NULL)
		{
			p2 = p2->next;
		}
		/* p1(XX1)->XX3(XX2)->p2->XX4->... */
	}
	return head;
}

/**
 *  @name        : void find_mid_node(list_t *head)
 *	@description : find the mid node of the list and print it's number
 *	@param		 : head(the head of the list)
 *	@return		 : none
 *  @notice      : in one circulation low=low->next quick=quick->next->next(if can be done)
 */
void find_mid(list_t *head)
{
	list_t *low=head, *quick=head->next;
	while(quick != NULL)
	{
		quick = quick->next;
		if(quick != NULL)
		{
			quick = quick->next;
		}
		low = low->next;
	}
	printf("The number of the middle node is %d.\n", low->data);
}

/**
 *  @name        : void create_ring(list_t * head)
 *	@description : create a list with a ring
 *	@param		 : head(the head of the list)
 *	@return		 : none
 *  @notice      : need user order a number where the ring begin
 				   p1 is the last of the list
 				   after using the number user gives to find p2
 				   p1->next = p2
 */
void create_ring(list_t *head)
{
	int lenth=1,flag=0;
	list_t *p1,*p2;
	p1 = head;
	while(p1->next != NULL)
	{
		p1 = p1->next;
		lenth++;
	}
	while(1)
	{
		printf("The lenth of the list is %d,please give me the number where you want to create a ring:\n", lenth);
		scanf("%d", &flag);
		if(flag <= lenth)
			break;
		else
		{
			printf("Please give me the right number!\n");
		}
	}
	p2 = head;
	lenth = 1;
	while(lenth != flag)
	{
		p2 = p2->next;
		lenth++;
	}
	p1->next = p2;
}


/**
 *  @name        : int check_ring()
 *	@description : check whether there is a ring in the list of not
 *	@param		 : head(the head of the list)
 *	@return		 : int
                   1 means yes 
				   0 means no 
 *  @notice      : use the way with low pointer and quick pointer
 				   if there is a ring,the low pointer will meet with the quick pointer
 */
int check_ring(list_t *head)
{
	list_t *low,*quick;
	low = head;
	quick = head;
	while(quick->next != NULL)
	{
		quick = quick->next;
		if(quick == low)
			return 1;
		if(quick->next != NULL)
		{
			quick = quick->next;
		}
		if(quick == low)
			return 1;
		low = low->next;
		if(quick == low)
			return 1;
	}
	return 0;
}

/**
 *  @name        : void check_and_destroy_ring()
 *	@description : check whether there is a ring in the list and if yes return it into normal list
 *	@param		 : head(the head of the list)
 *	@return		 : none
 *  @notice      : use another way to finish the funsion like this:
 				   read all the node then get their next node become head and their address into p
 				   then if we find there is a node's(p2) next is head,there is a ring
 				   last,we can use the p to recover the list
 				   by the way,if we find that the p is full(a&7 == 8),we should realloc the p
 */
void check_and_destroy_ring(list_t *head)
{
	int a=0;/* a is used to get the lenth of p */
	list_t** p=(list_t**)malloc(sizeof(list_t*)*8);
	/* the p is used to get all the node's address */
	list_t *p1, *p2;
	p1 = head;
	if(p1->next == NULL)
	{
		printf("There isn't a ring in the list.\n");
		free(p);
		return;
	}
	*(p + a++) = p1;
	while(1)
	{
		p2 = p1->next;
		p1->next = head;
		if(p2->next == head)
		{
			printf("There is a ring in the list,and the ring node's number is %d.\n", p2->data);
			printf("Now I will return it into a normal list.\n");
			destroy_ring(p,a);
			free(p);
			return;
		}
		*(p + a++) = p2;
		if(p2->next == NULL)
		{
			printf("There isn't a ring in the list.\n");
			destroy_ring(p,a);
			return;
		}
		if(a&7 == 0)/* check whether the p is full or not */
		{
			p = (list_t**)realloc(p, a+8);
		}
		p1 = p2;
	}
}

/**
 *  @name        : void destroy_ring(list_t** p, int lenth)
 *	@description : use the address of the p to create a normal list
 *	@param		 : p(all the node's address of the list) lenth(the lenth of the list)
 *	@return		 : none
 *  @notice      : none
 */
void destroy_ring(list_t** p,int lenth)
{
	int i;
	for(i=0; i<lenth-1; i++)
	{
		(p[i])->next = p[i+1];
	}
	(p[i])->next = NULL;
}


/**
 *  @name        : void reverse(list_t *head)
 *	@description : reverse the list without recursion
 *	@param		 : head(head of the list)
 *	@return		 : none
 *  @notice      : p1->p2->p3    p1 and p2 is what we want to change
 				   then p2->next = p1
				   remove them into next node
 */
list_t* reverse(list_t *head)
{
	list_t *p1, *p2, *p3;
	p1 = head;
	if(p1->next != NULL)
	{
		p2 = p1->next;
		p1->next = NULL;
	}
	else 
		return p1;

	/**
	 * old list:p2->...->NULL 
	 * another list:p1(head)->NULL
	 */
	while(p2 != NULL)
	{
		p3 = p2->next;
		/**
		 *p2->p3->...->NULL
		 *p1->...->head->NULL
		 */
		p2->next = p1;
		/**
		 * p3->...->NULL
		 * p2->p1->...->head->NULL
		 */
		p1 = p2;
		p2 = p3;
		/**
		 *p2(p3)->...->NULL
		 *p1->...->NULL
		 */
	}
	return p1;
}

/**
 *  @name        : void reverse_recursion(list_t *head)
 *	@description : reverse the list with recursion
 *	@param		 : head(head of the list)
 *	@return		 : none
 *  @notice      : Before doing this function,we make p2=head->next and p1=head the head->next=NULL
                   then p3=p2->next,after doing this function once p2->next=p1
                   then p1=p2,p2=p3 continue...
 */
list_t* reverse_recursion(list_t *p1, list_t *p2)
{
	if(p2 == NULL)
		return p1;
	list_t *p3 = p2->next;
	p2->next = p1;
	return reverse_recursion(p2,p3);
}

/**
 *  @name        : void insert_list(list_t *p, list_t *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : none
 *  @notice      : None
 */
void insert_list(list_t *p, list_t *q)
{
	list_t *p1=p->next;
	p->next = q;
	q->next = p1;
}

/**
 *  @name        : void delete_node(list_t *p, int *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : int
 				   1 means having deleted
 				   0 means having not deleted
 *  @notice      : None
 */
int delete_node(list_t *p, int *e)
{
	
	list_t *p1=p->next;
	if(p1 == NULL)
	{
		printf("There is not any node after p!\n");
		return 0;
	}
	else
	{
		*e = p1->data;
		p1 = p1->next;
	}
	free(p->next);
	p->next = p1;
	return 1;
}

/**
 *  @name        : int search_list(List_t* head, int e)
 *	@description : find the first node in the list according to e
 *	@param		 : L(the head node), e
 *	@return		 : int
 				   1 : have found
 				   0 : haven't found
 *  @notice      : None
 */
int search_list(list_t *head, int e)
{
	list_t *p1=head;
	while(p1 != NULL)
	{
		if(p1->data == e)
			return 1;
		p1 = p1->next;
	}
	return 0;
}

/**
 *  @name        : void destroy_list(list_t *head) 
 *	@description : destroy the list and quit
 *	@param		 : head(head of the list
 *	@return		 : none
 *  @notice      : none
 */
void destroy_list(list_t* head)
{
	list_t *p1, *p2;
	p1 = head;
	while(p1 != NULL)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
}
