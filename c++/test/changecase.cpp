#include <stdio.h>

void upper(char* tmp)
{
	int i;
	for(i=0;tmp[i]!='\0';i++)
		tmp[i] = tmp[i] & 0xdf;
}

void lower(char* tmp)
{
	int i;
	for(i=0;tmp[i]!='\0';i++)
		tmp[i] = tmp[i] | 0x20;
}


int main()
{
	char a[100];
	int i;
	gets(a);
	puts(a);
	lower(a);
	puts(a);
	upper(a);
	puts(a);
	return 0;
}
