#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"QG_count_header.h"

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
		scanf("%s", s);
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
	printf("This system can accept something like '-2', but you can give me '(0-2)'!\n");
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
