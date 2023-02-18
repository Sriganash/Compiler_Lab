#include<stdio.h>
#include<string.h>
#include<ctype.h>

struct TAC
{
	char LHS;
	char op;
	char x;
	char y;
};

struct TAC tac[50];
char expr[50],ex[50];
int inc=1;

int k=0;

int priority(char x)
{
    if(x == '+' || x == '-')
        return 1*inc;
    if(x == '*' || x == '/')
        return 2*inc;
    return 0;
}


void convert()
{
  while(strlen(ex)>1)
  {
  int max=-1;
	  for(int i=0;ex[i]!='\0';i++)
    {
        if(ex[i]=='(') inc++;
        else if(ex[i]==')') inc--;
        if(max!=-1 && priority(ex[max])<priority(ex[i]))
          max=i;
        else if(max==-1)
          max=i;
         
    }
  		if(max!=-1)
  		{
  			tac[k].LHS='0'+k;
  			tac[k].op=ex[max];
  			tac[k].x=ex[max-1];
  			tac[k].y=ex[max+1];
  			
  			ex[max-1]=tac[k].LHS;
  			k++;
  			for(int i=max;ex[i+2]!='\0';i++)
  			{
  				ex[i]=ex[i+2];
  			}
  			ex[strlen(ex)-2]='\0';

        if(ex[max-2]=='(' && ex[max]==')')
        {
          ex[max-2]=ex[max-1];
          for(int i=max-1;i<strlen(ex)-2;i++)
            {
              ex[i]=ex[i+2];
            }
          ex[strlen(ex)-2]='\0';
          
        }
        }

	}
}

void main()
{
	printf("\nEnter the expression :\n");
	scanf(" %s",expr);
	int r = strlen(expr);

	strncat(ex,&expr[2],strlen(expr)-2);
	convert();

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

	printf("\n%c = t%c\n",expr[0],tac[k-1].LHS);
	
}