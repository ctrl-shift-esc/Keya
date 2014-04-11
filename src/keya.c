#include <stdio.h>
#define TABLE 4
char a[TABLE * TABLE]={0};
char *p = a;
long pos;
int main(int argc, char **argv)
{
	/* Error Handling needed.*/
	int c;
	FILE *fp;
	fp = fopen(argv[1],"r");
	while((c = fgetc(fp)) != EOF)
	{
		if (c=='8')p=p-TABLE;
		if (c=='2')p=p+TABLE;
		if (c=='4')--p;
		if (c=='6')++p;
		if (c=='+'){++*p;}
		if (c=='-')--*p;
		if (c=='.'){putchar(*p);}
		if (c==',')*p = getchar();
		if (c=='[')
		{
			pos = ftell(fp);
			if (*p == 0)
			{
				while(fgetc(fp)!=']');
			}
		}
		if (c==']')
		{
			if(*p !=0)
			{
				fseek(fp,pos,SEEK_SET);
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