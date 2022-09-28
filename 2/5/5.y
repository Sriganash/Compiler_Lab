%{
    #include<stdio.h>

%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%left '(' ')'
%%
Arithmetic_Expression : E {
                        printf("\nEntered arithmetic expression is Valid\n\n");
                        };

                    E : 
                        E'+'E {$$=$1+$3,printf("\n%d + %d = %d",$1,$3,$$);} 
                        | E'-'E {$$=$1-$3,printf("\n%d + %d = %d",$1,$3,$$);} 
                        |E'*'E {$$=$1*$3,printf("\n%d + %d = %d",$1,$3,$$);} 
                        |E'/'E {$$=$1/$3,printf("\n%d + %d = %d",$1,$3,$$);} 
                        |'('E')' {$$=$2,printf("\n(%d)",$2);} 
                        | NUMBER {$$=$1,printf("\n%d",$1);} 
                        ;

%%

  
void yyerror()
{
   printf("\nEntered arithmetic expression is Invalid\n\n");
}

void main()
{
   printf("\nEnter Any Arithmetic Expression :\n");
  
   yyparse();
}