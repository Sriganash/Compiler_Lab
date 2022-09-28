%{
    #include<stdio.h>
    #include<stdlib.h>

    int v=0;
    int c=0;
%}

vowel [aeiouAEIOU]
consonant [^aeiouAEIOU]

%%

{vowel} {v++;}
{consonant} {c++;}

%%

int yywrap(){}

void main()
{
    printf("\nEnter the input: ");
    yylex();

    printf("\nVowel = %d",v);
    printf("\nConsonant = %d\n",c-1);
    
}