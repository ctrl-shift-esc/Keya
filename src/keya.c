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
#define TABLE 20

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
		switch (c)
		{
			case '8':
					p=p-TABLE;
					break;
			case '2':
					p=p+TABLE;
					break;
			case '4':
					--p;
					break;
			case '6': 
					++p;
					break;
			case 'r':
					p=a;
					a[TABLE*TABLE]={0};
					break;
			case '+':
					++*p;
					break;
			case '-':
					--*p;
					break;
			case '.':
					putchar(*p);
					break;
			case ',':
					*p = getchar();
					break;
			case '[':
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
					break;
			case ']':
					if(*p !=0)
					{
						fseek(fp,pos[count],SEEK_SET);
					}
					else
					{
						count--;
					}
					break;
			case '>':
					*(p+1) = *p;
					break;
			case '<':
					*(p-1) = *p;
					break;
			case '^':
					*(p-TABLE) = *p;
					break;
			case '_':
					*(p+TABLE) = *p;
					break;
		}
	}
	fclose(fp);
	printf("\n");
}
