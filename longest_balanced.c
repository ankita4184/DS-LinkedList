#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct stack{
	int top;
	char arr[13];
}so;
so s;
void push(char a)
{
	s.arr[s.top++] = a;
}
char pop()
{
	char a = s.arr[s.top - 1];
	s.top --;
	return a;
}
int max = 0;
void longest(char *ar)
{
	int i = 0, j = 0, k = 0;
	char b;
	while(ar[i] != '\0')
	{ 
    	if(ar[i] == '(' || ar[i] == '{' || ar[i] == '[')
			push(ar[i]);
		else
		{   
            b = pop();
            if((ar[i] == '}' && b == '{') || (ar[i] == ']' && b =='[') || (ar[i] == ')' && b  == '('))
			    j+=2;
	        else
                {
                    printf("%d\n", j);
                    j = 0;
                }
			
		}
		i++;
    }
}
int main()
{
	s.top = 1;
	char ar[13] = { '{', '{', '}', '}', '[', '[', '(', ')', '(', ')', '(', ')','\0'};
	longest(ar);
    printf("%d", max);
	return 0;
}
