#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

num_stack_t *num=(num_stack_t*)malloc(sizeof(num_stack_t));
sym_stack_t *sym=(sym_stack_t*)malloc(sizeof(sym_stack_t));

int main()
{
	char s[MAX_NUM+1];
	num->p = (float*)calloc(MAX_NUM/2,sizeof(float));
	sym->p = (char*)calloc(MAX_NUM/2,sizeof(char));
	while(1)
	{
		
		show();
		gets(s); 
		check_all(s);
	}
	free_room();
	return 0;
}

/**
 *  @name        : void show()
 *	@description : show what user shoule konw:
 *	@param		 : none
 *	@return		 : none
 *  @notice      : none
 */
void show()
{
	printf("Please don't give me what is more than %d chars or with any 'space'!\n", MAX_NUM);
	printf("This system cann't accept something like '-2', but you can give me '(0-2)'!\n");
	printf("Please don't give me the number which is too big or small.\n");
	printf("At last,we are sorry that his system can not get a very perfect answer sometimes.\n");
	printf("Now please give me what you want to count:\n");
	num->p[0] = 0;
	num->number = 0;
	sym->number = 0;
}

/**
 *  @name        : void free_room()
 *	@description : free the room we have got
 *	@param		 : none
 *	@return		 : none
 *  @notice      : none
 */
void free_room()
{
	free(num->p);
	free(sym->p);
	free(num);
	free(sym);
}

/**
 *  @name        : void check_all(char *s)
 *	@description : check whether there something wrong and if not do counting
 *	@param		 : s(the formula user give)
 *	@return		 : none
 *  @notice      : none
 */
void check_all(char *s)
{
	if(strlen(s) >= MAX_NUM)
	{
		system("cls");
		printf("In: %s\n", s);
		printf("What you give me is too long!\n");
		return;
	}
	if(*s =='\0')
	{
		system("cls");
		printf("Please give me something!\n");
		return;
	}
	if(*s!='(' && (*s<'0' || *s>'9'))
	{
		system("cls");
		printf("In: %s\n", s);
		printf("Please don't give me something else before the number!\n");
		return;
	}
	int flag=check(s);
	if(flag == 1)
	{
		count(s);
		system("cls");
		printf("%s =\n\t%f\n\n", s, num->p[0]);
		printf("Now you can continue :\n");
	}
	else if(flag == -1)
	{
		system("cls");
		printf("In: %s\n", s);
		printf("There are two symbol together!\n");
	}
	else if(flag == -2)
	{
		system("cls");
		printf("In: %s", s);
		printf("The number you give me is too big!\n");
	}
	else if(flag == -3)
	{
		system("cls");
		printf("In: %s\n", s);
		printf("The number you giev me is too small!\n");
	}
	else if(flag == -4)
	{
		system("cls");
		printf("In: %s\n", s);
		printf("Please give right braces!\n");
	}
	else if(flag == -5)
	{
		system("cls");
		printf("In: %s\n", s);
		printf("Please don't give me something else!\n");
	}
	else if(flag == -6)
	{
		system("cls");
		printf("In: %s\n");
		printf("There is something wrong about '.',please check it again!\n");
	}
}

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
int check(char* s)
{
	int symbol_flag=1;                  /* check whether there are tow symbols together */ 
	int number_flag1=0, number_flag2=0; /* check whether the number is above 
									     * flag1 is something before .
									     * flag2 is something after .
									     */
	int flag=1;                         /* check whether it is before or after '.' */ 
	int braces_flag=0;				    /* check whether the braces is right */
	for(int i=0; s[i]!='\0'; i++)
	{
		if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')
		{
			if(symbol_flag == 0)
				symbol_flag = 1;
			else
				return -1;
			/* when meeting number,symbol_flag = 0,which can check whether there tow counting symbol together */
			if(number_flag1 > 6)
				return -2;
			else 
				number_flag1 = 0;
			if(number_flag2 > 6)
				return -3;
			else
				number_flag2 = 0;
			/* check the number before the counting symbol is too big or too small */
			flag = 1;
			/* after this counting symbol,we should get the lenth of the path bigger than 1 of the number */
		}
		else if(s[i] <= '9' && s[i] >= '0')
		{
			if(flag == 1)
				number_flag1++;
			else if(flag == 2)
				number_flag2++;
			symbol_flag = 0;
		}
		else if(s[i] == '.')
		{
			if(flag == 1)
				flag = 2;
			else
				return -6;
			/* It is wrong that there some int number before '.' */
		}
		else if(s[i] == '(')
			braces_flag++;
		else if(s[i] == ')')
		{
			if(braces_flag <= 0)
				return -4;
			/* if so,it is wrong that the number of '(' is smaller than that of ')' whenever */
			braces_flag--;
		}
		else
			return -5;
	}
	if(number_flag1 > 6)
		return -2;
	if(number_flag2 > 6)
		return -3;
	if(braces_flag != 0)
		return -4;
	/* it's wrong that the number of '(' is not as same as that of ')' */
	return 1;
}

/**
 *  @name        : float pop_num()
 *	@description : pop a number from number stack
 *	@param		 : none
 *	@return		 : what is poped
 *  @notice      : none
 */
float pop_num()
{
	(num->number)--;
	return num->p[num->number];
}

/**
 *  @name        : void push_num(float a)
 *	@description : push a number into number stack
 *	@param		 : a(what is pushed)
 *	@return		 : none
 *  @notice      : none
 */
void push_num(float a)
{
	num->p[num->number] = a;
	num->number++;
}

/**
 *  @name        : void sym_count(char a)
 *	@description : from the number stack pop tow number,
 				   then count them two with char a,
 				   lastly push it into the nuber stack
 *	@param		 : a('*' or '/' or '-' or '+')
 *	@return		 : none
 *  @notice      : none
 */
void sym_count(char a)
{
	if(a == '+')
		push_num(pop_num() + pop_num());
	else if(a == '-')
		push_num(-(pop_num() - pop_num()));
	else if(a == '*')
		push_num(pop_num() * pop_num());
	else if(a == '/')
		push_num(1/(pop_num() / pop_num()));
}

/**
 *  @name        : void push_sym(char a)
 *	@description : push the symbol and then depend on it to do something
 *	@param		 : a(the right symbol)
 *	@return		 : none
 *  @notice      : none
 */
void push_sym(char a)
{
	if(a == '*' || a == '/')
	{
		if(sym->p[sym->number-1] == '*' || sym->p[sym->number-1] == '/')
			sym_count(sym->p[--(sym->number)]);
		sym->p[(sym->number)++] = a;
	}
	/* if the last one is '*' or '/',push it and then push a */
	else if(a == '+' || a == '-')
	{
		int i=sym->number-1;
		if(i>=0)
			while(sym->p[i] != '(' && i>=0)
			{
				sym_count(sym->p[i]);
				sym->number--;
				i--;
			}
		sym->p[(sym->number)++] = a;
	}
	/* clear all the symbol until meeting '(' or the stack is empty */
	else if(a == '(')
	{
		sym->p[(sym->number)++] = a;
	}
	/* push it just OK */
	else if(a == ')')
	{
		while(sym->p[sym->number-1] != '(')
		{
			sym_count(sym->p[--(sym->number)]);
		}
		(sym->number)--;
		/* push the '(' from symbol stack */
	}
	/* clean all the symbol until meeting '(' then pop the '(' */
}

/**
 *  @name        : void count(char *s)
 *	@description : do counting
 *	@return		 : none
 *  @notice      : none
 */
void count(char *s)
{
	float a,bflag;
	int i=0;
	while(s[i] == '(')
		sym->p[(sym->number)++] = s[i++];
	/* push the '(' into the symbol stack */
	while(*(s+i) != '\0')
	{
		a = 0.0;     /* get the number in the formula */
		bflag = 0.1; /* which can help to get a */ 
		while(s[i]>='0' && s[i]<='9')
			a = a*10+s[i++]-'0';
		/* get what is bigger than 1 */
		if(s[i] == '.')
		{
			i++;
			while(s[i]>='0' && s[i]<='9')
			{
				a += bflag*(s[i++]-'0');
				bflag /= 10;
			}
		}
		/* get other */
		push_num(a);
		if(s[i] != '\0')
			while((s[i]<'0' || s[i]>'9') && s[i]!='\0')
				push_sym(s[i++]);
		/* push the symbol */
	}
	while(sym->number > 0)
		sym_count(sym->p[--(sym->number)]);
	/* clear the symbol stack */
}
