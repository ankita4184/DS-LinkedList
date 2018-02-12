#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct queue 
{
	int arr[10];
	int head;
	int tail;
}que;
que q;
int size()
{
	return abs(q.tail - q.head);
}
void print()
{
	int i;
	for(i = 0; i < 10; i++)
		printf("%d",q.arr[i]);
	printf("\n%d %d\n",q.head,q.tail);
}
int isEmpty()
{
	if(size() == 0)
		return 1;
	return 0;
}
int isFull()
{
	if(size() == 10)
		return 1;
	return 0;
}
 


void nqueue(int d)
{
	int p = isFull();
	if(p == 1)
	{
		printf("array full\n");
		return;
	}
	else
	{
		if(q.head >= 10 && q.tail > 0)
		{ q.head %= 10; }
		q.arr[q.head++] = d;
	}
	print();
}
int dqueue()
{
	int temp;
	int p = isEmpty();
	if(p == 1)
	{
		printf("array empty\n");
		return -1;
	}
	else
	{
		if(q.tail >= 10)
			q.tail %= 10;
		temp = q.arr[q.tail];
		q.arr[q.tail] = 0;
		q.tail++;
	}
	print();
	return temp;
}
int main()
{
	q.head = 0;
	q.tail = 0;
	int i,d;
	scanf("%d", &i);
	while( i != 0 )
	{
		switch(i)
		{
			case 1 :
				scanf("%d", &d);
				nqueue(d);
				break;
			case 2 :
				printf("%d\n",dqueue());
				break;
			case 3 :
				printf("%d\n", isEmpty());
				break;
			case 4 :
				printf("%d\n", isFull());
				break;
			case 5 :
				printf("%d\n", size());
				break;
		}
		scanf("%d", &i);
	}
	return 0;
}

		
