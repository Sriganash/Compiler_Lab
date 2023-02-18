#include <stdio.h>
#include <string.h>

struct statement 
{
    char lhs[2];
    char rhs[4];
};

void move(char a, char b) 
{
	printf("MOV AX, %c\n", b);
	printf("MOV %c, AX\n", a);
}

void add(char a, char b, char c) 
{
	printf("MOV AX, %c\n", b);
	printf("MOV BX, %c\n", c);
	printf("ADD AX, BX\n");
	printf("MOV %c, AX\n", a);
}

void sub(char a, char b, char c) 
{
	printf("MOV AX, %c\n", b);
	printf("MOV BX, %c\n", c);
	printf("SUB AX, BX\n");
	printf("MOV %c, AX\n", a);
}

void mul(char a, char b, char c) 
{
	printf("MOV AX, %c\n", b);
	printf("MOV BX, %c\n", c);
	printf("MUL AX, BX\n");
	printf("MOV %c, AX\n", a);
}

void div(char a, char b, char c) 
{
	printf("MOV AX, %c\n", b);
	printf("MOV BX, %c\n", c);
	printf("DIV AX, BX\n");
	printf("MOV %c, AX\n", a);
}

void main() 
{
	int n;

	printf("Enter the number of statements in Intermediate Code: ");
	scanf("%d", &n);
	struct statement statements[n];

	printf("Enter the statements:\n");
	for(int i = 0; i < n; i++) 
	{
		scanf(" %s, %s", statements[i].lhs, statements[i].rhs);
	}

	printf("\nGenerated Code:\n");
	for(int i = 0; i < n; i++) 
	{
		if(strlen(statements[i].rhs) == 1) 
		{
			move(statements[i].lhs[0], statements[i].rhs[0]); 
		} 
		else 
		{
			switch(statements[i].rhs[1]) 
			{
			case '+':
				add(statements[i].lhs[0], statements[i].rhs[0], statements[i].rhs[2]);
				break;
			case '-':
				sub(statements[i].lhs[0], statements[i].rhs[0], statements[i].rhs[2]);
				break;
			case '*':
				mul(statements[i].lhs[0], statements[i].rhs[0], statements[i].rhs[2]);
				break;
			case '/':
				div(statements[i].lhs[0], statements[i].rhs[0], statements[i].rhs[2]);
				break;
			default:
				printf("Invalid statement!\n");
				return;
			}
		}
	}
}
