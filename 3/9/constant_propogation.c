#include<stdio.h>
#include<string.h>

char code[20][20];

void main()
{
	printf("\nEnter the number of lines : ");
	int n;
	scanf("%d",&n);

	printf("\nEnter the codes : \n");

	for(int i=0;i<n;i++)
		scanf(" %s",code[i]);

	printf("\nAfter constant_propogation is applied :\n");

	for(int i=0;i<n;i++)
	{
		char temp[20];
		char c;
		strcpy(temp,"");
		int flag=1;
		for(int j=2;j<strlen(code[i]);j++)
		{
			c=code[i][0];
			if(code[i][j]>='0' && code[i][j]<='9')
			{
				strncat(temp,&code[i][j],1);
			}
			else
			{
				flag=0;
				break;
			}
			//printf("\t%s",temp);
		}
		if(flag)
		{
			for(int j=i;j<n;j++)
			{
				//printf("%d ",i);
				for(int k=2;k<strlen(code[j]);k++)
				{
					if(code[j][k]==c)
					{
						char t[20];
						strcpy(t,"");
						for(int x=k+1;x<strlen(code[j]);x++)
						{
							strncat(t,&code[j][x],1);
						}

						//printf("\n%s",t);
						char r[20];
						strcpy(r,"");
						for(int x=0;x<k;x++)
						{
							strncat(r,&code[j][x],1);
						}
						//printf("%s",r);
						strcat(r,temp);
						strcat(r,t);
						strcpy(code[j],r);
						//printf("\n%s",code[j]);
					}
				}
			}
		}
		else
			continue;

	}
	for(int i=0;i<n;i++)
		printf("\n%s",code[i]);
	printf("\n");
}
