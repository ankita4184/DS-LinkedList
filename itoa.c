#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int a = 1;
	int *b = &a;
	char c = (b);
	printf("%c",c);
}
