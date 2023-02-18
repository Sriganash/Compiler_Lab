#include<stdio.h>
#include<string.h>
#include<ctype.h>

char ex[50];
char expr[50];
char stack[50];
char post[50];
char LHS;

struct TAC
{
	char LHS;
	char op;
	char x;
	char y;
};

struct TAC tac[50];

int top;


void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

void convert()
{
	int k=0;
	strcpy(stack,"");

	for(int i=0;i<strlen(post);i++)
	{
		if(isalnum(post[i]))
		{
			push(post[i]);
		}
		else
		{
			tac[k].LHS='0'+k;
			tac[k].op=post[i];
			tac[k].y=pop();
			tac[k].x=pop();
			push('0'+k);
			k++;
		}
	}
	for(int i=0;i<k;i++)
	{
		printf("\n");
		if(tac[i].LHS >='0' && tac[i].LHS <='9')
		{
			printf("t%c = ",tac[i].LHS);
		}
		else
		{
			printf("%c = ",tac[i].LHS);
		}
		if(tac[i].x >='0' && tac[i].x <='9')
		{
			printf("t%c ",tac[i].x);
		}
		else
		{
			printf("%c ",tac[i].x);
		}

		printf("%c ",tac[i].op);

		if(tac[i].y >='0' && tac[i].y <='9')
		{
			printf("t%c ",tac[i].y);
		}
		else
		{
			printf("%c ",tac[i].y);
		}
	}

	printf("\n%c = t%c\n",LHS,tac[k-1].LHS);
}


int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

void infix_to_postfix()
{

    char *e, x;
    e = ex;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            strncat(post,e,1);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                strncat(post,&x,1);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
            {
            	char y=pop();
            	strncat(post,&y,1);
            }
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        char y=pop();
         strncat(post,&y,1);
    }
}

void main()
{
	top=-1;
	printf("\nEnter the exression : ");
	scanf(" %s",expr);

	strncat(ex,&expr[2],strlen(expr)-2);
	LHS = expr[0];
	infix_to_postfix();
	convert();
}