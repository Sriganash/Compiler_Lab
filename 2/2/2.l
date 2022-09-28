%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    int l=0;
    int w=0;
    int c=0;
%}

line [\n]
words [a-zA-Z0-9!@#$%^&*<>/?.()]+

%%
{line} {l++;}
{words} {w++, c+=strlen(yytext);}
%%

int yywrap(){}

void main()
{
    yyin=fopen("test.c", "r");
    yylex();

    printf("\nLINES: %d", l+1);
    printf("\nCHARACTERS: %d",c);
    printf("\nWORDS: %d\n", w);
}