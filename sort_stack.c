#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int r;
typedef struct stack{
	int top;
	int arr[10];
}so;
so s;
so d;
void push1(int i)
{
	d.arr[d.top++] = i;
}
void push(int i)
{
	s.arr[s.top++] = i;
}
int pop()
{
	int a = s.arr[s.top - 1];
	s.top --;
	return a;
}
int sort_recursive(int e)
{
int p,q;
if(s.top == 1)
	 return pop();
else
{
		q = pop();
		p = sort_recursive(e);
		if(p > q)
		{
			push(p); 
			if(s.top == e)
				{push1(q); return 0;}
			else
				{return q;}
		}
		else
		{
			push(q); 
			if(s.top == e)
			       {push1(p); return 0;}
			else
				{return p;}
		}
		
	}
	

return 0;
}
void print()
{
int i;
for(i = 0; i < d.top; i++)
{
	printf(" %d ",d.arr[i]);
}
}
int main()
{
	s.top = 0;
	d.top = 0;
	int k,i,e = 9;
	push(10); push(9); push(6); push(3); push(2); push(4); push(5); push(7); push(8); push(1);
	for(i = 0; i < 10; i++)
 {	 k = sort_recursive(e--);}
	push1(k);
	print();
	return 0;
}
