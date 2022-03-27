#define MAX_NUM 100

typedef struct num_stack_t
{
	float *p;
	int number;
}num_stack_t;
typedef struct sym_stack_t
{
	char *p;
	int number;
}sym_stack_t;

/**
 *  @name        : void show()
 *	@description : show what user shoule konw:
 *	@param		 : none
 *	@return		 : none
 *  @notice      : none
 */
void show();

/**
 *  @name        : void free_room()
 *	@description : free the room we have got
 *	@param		 : none
 *	@return		 : none
 *  @notice      : none
 */
void free_room();

/**
 *  @name        : void check_all(char *s)
 *	@description : check whether there something wrong and if not do counting
 *	@param		 : s(the formula user give)
 *	@return		 : none
 *  @notice      : none
 */
void check_all(char *s);

/**
 *  @name        : int check(char *s)
 *	@description : check whether what user give is right or not
 *	@param		 : s(what the user give)
 *	@return		 :  1 --right
 				   -1 --symbol wrong like "+-" or "*-"
 				   -2 --something wrong about the part biger than 1 of the number
 				   -3 --something wrong about the part smaller than 1 of the number 
 				   -4 --braces wrong like "(()" or "())(" 
 				   -5 --something else happen wrong like "3ax6"
 				   -6 --something wrong about '.' like "3..6" or ".3"
 *  @notice      : none
 */ 
int check(char*s);

/**
 *  @name        : float pop_num()
 *	@description : pop a number from number stack
 *	@param		 : none
 *	@return		 : what is poped
 *  @notice      : none
 */
float pop_num();

/**
 *  @name        : void push_num(float a)
 *	@description : push a number into number stack
 *	@param		 : a(what is pushed)
 *	@return		 : none
 *  @notice      : none
 */
void push_num(float a);

/**
 *  @name        : void sym_count(char a)
 *	@description : from the number stack pop tow number,
 				   then count them two with char a,
 				   lastly push it into the nuber stack
 *	@param		 : a('*' or '/' or '-' or '+')
 *	@return		 : none
 *  @notice      : none
 */
void push_sym(char a);

/**
 *  @name        : void push_sym(char a)
 *	@description : push the symbol and then depend on it to do something
 *	@param		 : a(the right symbol)
 *	@return		 : none
 *  @notice      : none
 */
void sym_count(char a);

/**
 *  @name        : void count(char *s)
 *	@description : do counting
 *	@return		 : none
 *  @notice      : none
 */
void count(char *s);
