%{
    #include<stdio.h>
    #include<stdlib.h>

    int comment=0;
%}

operator [+*\-&/%=!#\[\]]|(<=)|(>=)|[<>]
letter [a-zA-Z]
digit [0-9]
literal (["]({letter}|{operator}|{digit}|[\\n]|[\\t]|[ ])*["])|{digit}+
identifier ({letter}|_)({letter}|_|{digit})*

%%
\/\/.*   ;
\/\*.* ;
.*\*\/.*  ;
void|main|include|define|printf|scanf|fgets|for|while|int|char|strlen|FILE|fopen|feof|NULL|if|return|double|continue|break|strcmp|strcat|fflush|fscanf|fprintf|strcpy|return {printf("\n%s, keyword",yytext);}
{operator} {printf("\n%s, operator",yytext);}
"1","2","3","4","5","6","7","8","9","0" {printf("\n%s, literal",yytext);}
{literal} {printf("\n%s, literal",yytext);}
"{"|"}"|"("|")"|";"|","|"." {printf("\n%s, seperator",yytext);}
{identifier} {printf("\n%s, identifier",yytext);}
%%

int yywrap(){}
void main()
{
    yyin=fopen("test.c", "r");
    yylex();
}
