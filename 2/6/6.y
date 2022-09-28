%{
    #include<stdio.h>

    int flag=0;
%}

%token digit letter

%%
start : letter s 
s     : letter s
        |digit s
        |
        ;
%%
 
int yyerror()
{
    printf("\nIts not an identifier");
    flag=1;
    return 0;
}

void main()
{
    printf("\nEnter the identifier: ");
    yyparse();

    if(!flag)
        printf("\nIt is an identifier");
} 