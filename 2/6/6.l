%{
    #include "y.tab.c"
%}

%%
[a-zA-z_][a-zA-Z_0-9]* {return letter;}
[0-9] {return digit;}
[\n]    {return 0;}
. {return yytext[0];}

%%

int yywrap(){}
