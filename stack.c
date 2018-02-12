#include<stdio.h>
typedef struct stack {
	int top;
	int a[10];
//	void push(int);	
}s;
s p;
void push(int i)
{
	if(p.top == 10)
		printf("Error");
	else
		p.a[++p.top] = i;
}
int pop()
{
	if(p.top == -1)
		{printf("Error"); return 0; }
	else
		return p.a[p.top--];
}
int isEmpty()
{
	if(p.top >= 0)
		return 0;
	else
		return 1;

}
int main()
{
	s.top = -1;
	push(10);
	printf("%d  %d",isEmpty(),pop());

}
