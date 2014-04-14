/*****************************************************************************************************
*								KEYA - An esoteric language by Krishna Sudhakar                      *
*                   This software has been licensed under the GNU General Public License v3.         *
*                                                                                                    *
*                                                                                                    *
*  @author: Krishna Sudhakar                                                                         *
*  @creation_date: 11 April 2014 (2014-04-11 15:32:00 CEST)											 *
*  @contact: me@krishnasudhakar.me																	 *
******************************************************************************************************/

#include <stdio.h>
#define TABLE 10

char a[TABLE * TABLE]={0};
char *p = a;

long pos[1000];
int count = 0;

int main(int argc, char **argv)
{
	int c, temp;
	FILE *fp;
	fp = fopen(argv[1],"r");

	while((c = fgetc(fp)) != EOF)
	{
		if (c=='8')p=p-TABLE;
		if (c=='2')p=p+TABLE;
		if (c=='4')--p;
		if (c=='6')++p;
		if (c=='r'){p=a;a[TABLE*TABLE]=0;}
		if (c=='+'){++*p;}
		if (c=='-')--*p;
		if (c=='.'){putchar(*p);}
		if (c==',')*p = getchar();
		if (c=='[')
		{
			count++;
			pos[count] = ftell(fp);
			if (*p == 0)
			{
				while(count !=0)
				{
					temp = fgetc(fp);
					if (temp == '[')
						count++;
					if (temp == ']')
						count--;
				}
			}

		}
		if (c==']')
		{
			if(*p !=0)
			{
				fseek(fp,pos[count],SEEK_SET);
			}
			else
			{
				count--;
			}
		}
		if (c=='>')
		{
			*(p+1) = *p;
		}
		if (c=='<')
		{
			*(p-1) = *p;
		}
		if (c=='^')
		{
			*(p-TABLE) = *p;
		}
		if (c=='_')
		{
			*(p+TABLE) = *p;
		}
	}
	fclose(fp);
	printf("\n");
}