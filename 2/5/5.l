%{
    #include<stdio.h>
    #include "y.tab.c"
    
    extern int yylval;
%}

digit [0-9]+

%%
{digit} {
            yylval=atoi(yytext);
            return NUMBER;
        }

[\t] ;
[\n] {return 0;}
. {return yytext[0];}
%%

int yywrap(){
    return 1;
}
