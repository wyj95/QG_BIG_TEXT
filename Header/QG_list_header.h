#include<stdio.h>
#include<stdlib.h>

typedef struct list_t
{
	int data;
	struct list_t* next;
}list_t;


/**
 *  @name        : list_t* create_list(int *lenth)
 *	@description : create a list
 *	@param		 : lenth
 *	@return		 : the head of the list
 *  @notice      : need user order the lenth of the list
 */
list_t* create_list(int *lenth);

/**
 *  @name        : void read_list(list_t* head)
 *	@description : print the number of all nodes of the list
 *	@param		 : head(the head of the list)
 *	@return		 : none
 *  @notice      : none
 */
void read_list(list_t* head);

/**
 *  @name        : void change(list_t *head)
 *	@description : change the even number node and the old number node
 *	@param		 : head(the head of the list)
 *	@return		 : none
 *  @notice      : none
 */
list_t* change(list_t *head);

/**
 *  @name        : void find_mid(list_t *head)
 *	@description : find the mid node of the list and print it's number
 *	@param		 : head(the head of the list)
 *	@return		 : none
 *  @notice      : none
 */
void find_mid(list_t *head);

/**
 *  @name        : void create_ring(list_t * head)
 *	@description : create a list with a ring
 *	@param		 : head(the head of the list)
 *	@return		 : none
 *  @notice      : need user order a number where the ring begin
 */
void create_ring(list_t *head);

/**
 *  @name        : int check_ring()
 *	@description : check whether there is a ring in the list of not
 *	@param		 : head(the head of the list)
 *	@return		 : int
 	               1 means yes
				   0 means no 
 *  @notice      : use the way with low pointer and quick pointer
 */
int check_ring(list_t *head);

/**
 *  @name        : void check_and_destroy_ring()
 *	@description : check whether there is a ring in the list and if yes return it into normal list
 *	@param		 : head(the head of the list)
 *	@return		 : none
 *  @notice      : use another way to finish the funsion
 */
void check_and_destroy_ring(list_t *head);

/**
 *  @name        : void destroy_ring(list_t** p, int lenth)
 *	@description : use the address of the p to create a normal list
 *	@param		 : p(all the node's address of the list) lenth(the lenth of the list)
 *	@return		 : none
 *  @notice      : none
 */
void destroy_ring(list_t** p, int lenth);

/**
 *  @name        : void reverse(list_t *head)
 *	@description : reverse the list without recursion
 *	@param		 : head(head of the list)
 *	@return		 : none
 *  @notice      : none
 */
list_t* reverse(list_t *head);

/**
 *  @name        : void reverse_recursion(list_t *head)
 *	@description : reverse the list with recursion
 *	@param		 : p1 p2
 *	@return		 : the head of reversed list
 *  @notice      : none
 */
list_t* reverse_recursion(list_t *p1, list_t *p2);

/**
 *  @name        : void insert_list(list_t *p, list_t *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : none
 *  @notice      : None
 */
void insert_list(list_t *p, list_t *q);

/**
 *  @name        : int delete_node(list_t *p, int *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : int
 				   1 means having deleted
 				   0 means having not deleted
 *  @notice      : None
 */
int delete_node(list_t *p, int *e);

/**
 *  @name        : int search_list(List_t* head, int e)
 *	@description : find the first node in the list according to e
 *	@param		 : head(head of the list), e
 *	@return		 : int
 				   1 : have found
 				   0 : haven't found
 *  @notice      : None
 */
int search_list(list_t *head, int e);

/**
 *  @name        : void destroy_list(list_t *head) 
 *	@description : destroy the list and quit
 *	@param		 : head(head of the list
 *	@return		 : the head of reversed list
 *  @notice      : noen
 */
void destroy_list(list_t* head);

