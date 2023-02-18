#include<stdio.h>
#include<string.h>

char production[20][20];
int count;
char string[20];
int ptr;

int E();
int E_();
int T();
int T_();
int F();

void main()
{
    ptr=0;
    count=6;
    strcpy(production[0],"E->E+T|T");
    strcpy(production[1],"T->T*F|F");
    strcpy(production[2],"F->(E)|id");

    for(int i=0;i<3;i++)
    {
        char c=production[i][0];
        
        if(c==production[i][3])
        {
            printf("\n%c->",c);
            int p=-1;
            for(int j=4;j<strlen(production[i]);j++)
            {
                if(production[i][j]=='|')
                {
                    p=j;
                    break;
                }
            }
            if(p!=-1)
            {
                for(int k=p+1;k<strlen(production[i]);k++)
                {
                    printf("%c",production[i][k]);
                }  
            }
            printf("%c'",c);
            printf("\n%c'->",c);
            for(int j=4;production[i][j]!='|';j++)
            {
                printf("%c",production[i][j]);
            }
            printf("%c'|#",c);
        }
        else
        {
            printf("\n%s",production[i]);
        }
    }

    printf("\n");

    printf("\nEnter the String: ");
    scanf(" %s",string);

    if(E() && ptr==strlen(string))
    {
        printf("\nString accepted\n");
    }
    else
    {
        printf("\nString not accepted\n");
    }
}

int F()
{
    if(string[ptr]=='(')
    {
        ptr++;
        if(E())
        {
            if(string[ptr]==')')
            {
                ptr++;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    else if(string[ptr]=='i')
    {
        ptr++;
        if(string[ptr]=='d')
        {
            ptr++;
            return 1;
        }
        return 0;
    }
    return 0;
}

int T_()
{
    if(string[ptr]=='*')
    {
        ptr++;
        if(F())
        {
            if(T_())
            {
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 1;
}

int T()
{
    if(F())
    {
        if(T_())
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

int E_()
{
    if(string[ptr]=='+')
    {
        ptr++;
        if(T())
        {
            if(E_())
            {
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 1;
}

int E()
{
    if(T())
    {
        if(E_())
        {
            return 1;
        }
        return 0;
    }
    return 0;
}