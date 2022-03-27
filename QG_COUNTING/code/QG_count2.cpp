#include<stdio.h>
#include"QG_count_header.h"

extern sym_stack_t *sym;
extern num_stack_t *num;
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
