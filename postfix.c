#include<stdio.h>
typedef struct stack{
	int arr[10];
	int top;
}st;
st s;
void push(int i)
{
	if(s.top == 10)
		printf("Error");
	else
		s.arr[++s.top] = i;
}
int pop()
{
	if(s.top == -1)
		printf("Error");
	else
		return s.arr[s.top--];
	return -1;
}
void display()
{
	int i;
	for(i=0;i<=s.top;i++)
	{
		printf("%d\t",s.arr[i]);
	}
	printf("\n");
}
int post_fix(char a[])
{
	int i = 0;
	while(a[i] != '\0')
	{
		if(a[i] == '+')
		{
			push(pop() + pop());
		}
		else if(a[i] == '-')
		{ 
			push(pop() -  pop());
		}
		else if(a[i] == '*')
		{ 
			push (pop() * pop());
		}
		else if(a[i] == '/')
		{ 
			push(pop() / pop());
		}
		else
		{
			push((int)(a[i]) - 48);
		}
		display();
		i++;

	}
	return pop(); 

}
int main()
{
	s.top = -1;
	char a[] = {'2', '3', '1', '*', '+', '9', '-', '\0'};
	printf("%d",post_fix(a));
	return 0;
}
