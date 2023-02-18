#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

char keywords[32][20];

FILE *f1;
FILE *fp;

char substr[50];

bool isValidDelimiter(char c)
{
	if(c == ' ' || c == '+' || c == '-' || c == '*' || c == '/' || c == ',' || c == ';' || 
		c == '<' || c == '>' || c == '=' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
			return true;
	return false;
}

bool isValidKeyword(char str[])
{
	for(int i=0;i<32;i++)
	{
		if(strcmp(keywords[i],str)==0)
			return true;
	}
	return false;
}

bool isValidInteger(char str[])
{
	int l=strlen(str);
	
	for(int i=0;i<l;i++)
	{
		if(str[i]!='0' && str[i]!='1' && str[i]!='2' && str[i]!='3' && str[i]!='4' && str[i]!='5' &&
			str[i]!='6' && str[i]!='7' && str[i]!='8' && str[i]!='9' || (str[i]=='-' && i > 0))
			return false;
	}
	return true;
}

bool isValidIdentifier(char str[])
{
	if(str[0]=='0' && str[0]=='1' && str[0]=='2' && str[0]=='3' && str[0]=='4' && str[0]=='5' &&
			str[0]=='6' && str[0]=='7' && str[0]=='8' && str[0]=='9')
			return false;
	int len=strlen(str);
	
	for(int i=0;i<len;i++)
	{
	printf("%d\n",i);
		if(isalpha(str[i])==0 && str[i]!='_')
			return false;
	}
	return true;
}


bool isValidOperator(char c)
{
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='<' || c=='>' || c=='=')
	{
		return true;
	}
	return false;
}

bool isRealNumber(char str[])
{
	int len=strlen(str);
	
	for(int i=0;i<len;i++)
	{
		if(str[i]!='0' && str[i]!='1' && str[i]!='2' && str[i]!='3' && str[i]!='4' && str[i]!='5' &&
			str[i]!='6' && str[i]!='7' && str[i]!='8' && str[i]!='9' || (str[i]=='-' && i > 0))
			return false;
		
	}
	return true;
}

char SubString(char str[],int left,int right)
{
	strcpy(substr,"");

	for(int i=left;i<=right;i++)
	{
		substr[i-left]=str[i];
	}
	substr[right-left+1]='\0';
}

void detectToken(char str[])
{
	int left,right;
	left=right=0;
	int l=strlen(str);
	FILE *error;
	error=fopen("Error.txt","w");
	while(right<l && left<=right)
	{
		if(str[left]=='/')
		{
			 if(str[left+1]=='*')
			 {
			 	while(str[strlen(str)-1] != '/' && str[strlen(str)-2] != '*')
			 	{
			 		printf("%s\n",str);
			 		fscanf(fp,"%s",str);
			 	}
			 	printf("%s\n",str);
			 	fgets(str,1024,fp);
			 }
			 else if(str[left+1]=='/')
			 {
			 	printf("%s\n",str);
			 	fgets(str,1024,fp);
			 }
		}
		if(isValidDelimiter(str[right])==false)
			right++;
		if(isValidDelimiter(str[right])==true && left==right)
		{
			if(isValidOperator(str[right])==true)
				if(isValidOperator(str[right-1])==true)
					fprintf(f1,"<%c%c,Operator>\n",str[right-1],str[right]);
				else
					fprintf(f1,"<%c,Operator>\n",str[right]);
			else
				fprintf(f1,"<%c,Seperator>\n",str[right]);
			right++;
			left=right;
		}
		else if(isValidDelimiter(str[right])==true && left!=right || (right == l && left!=right))
		{
			SubString(str,left,right-1);
			if(isValidKeyword(substr)==true)
				fprintf(f1,"<%s,keyword>\n",substr);
			else if(isValidInteger(substr)==true)
				fprintf(f1,"<%s,Constant>\n",substr);
			else if(isRealNumber(substr)==true)
				fprintf(f1,"<%s,Constant>\n",substr);
			/*else if(substr[0]=='"')
			{
				char temp[50];
				strcpy(temp,substr);
				do
				{
					fscanf(fp,"%s",str);
					strcpy(temp,str);
				}
				while(str[strlen(str)-1]!='"');
				fprintf(f1,"<%s,Literal>\n",temp);
			}*/
			else if(isValidIdentifier(substr)==true && isValidDelimiter(str[right-1])==false)
				fprintf(f1,"<%s,Identifier>\n",substr);
			else if(isValidIdentifier(substr)==false && isValidDelimiter(str[right-1])==false)
				fprintf(error,"Wrong Identifier %s\n",substr);
		
			left=right;
		}
	}
}

void main()
{
	int i=0;
	
	fp=fopen("keywords.txt","r");
	while(feof(fp)==0)
	{
		char key[20];
		fscanf(fp,"%s",key);
		strcpy(keywords[i++],key);
	}
	
	fclose(fp);
	
	fp=fopen("test.c","r");
	f1=fopen("tokens.txt","w");
	while(feof(fp)==0)
	{
		char str[50];
		fgets(str,1024,fp);
		detectToken(str);
	}
	
}	
