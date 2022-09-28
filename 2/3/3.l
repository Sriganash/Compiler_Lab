%{
    #include<stdio.h>
    #include<stdlib.h>

%}

string ([d-z]*(abc)*[d-z]*)*

%%
{string} {
            int n=strlen(yytext);
            for(int i=0;i<n-2;i++)
            {
                if(yytext[i]=='a' && yytext[i+1]=='b' && yytext[i+2]=='c')
                {
                    yytext[i]='A';
                    yytext[i+1]='B';
                    yytext[i+2]='C';
                }
            }

            printf("\n%s\n",yytext);
         }

%%

int yywrap(){}

void main()
{
    printf("\nEnter the input: ");
    yylex();
    
}