//THIS IS wrong because there will be different cases to be taken.
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void push(struct node **h, int i)
{
	struct node *t = *h;
	if((*h) == NULL)
	{
		struct node *a = (struct node*)malloc(sizeof(struct node));
		a -> data = i;
		a -> next = *h;
		*h = a;
	}
	else
	{
		struct node *a= (struct node*)malloc(sizeof(struct node));
		while(t -> next != NULL)
		{
			t = t -> next;
		}
		a -> data = i;
		a -> next = NULL;
		t -> next = a;
	}
}
void print(struct node *h)
{
	struct node *t = h;
	while( t != NULL)
	{
		printf("%d", t -> data);
		t = t -> next;
	}
}
void swap(struct node **h, int i, int j)
{
	struct node *a, *b;
	struct node *t1 = *h;
	struct node *t2 = *h;
	struct node *t3 = *h;
	while( t1 -> data != i)
	{
		t1 = t1 -> next;
	}
	a = t1;
	while(t2 -> data != j)
	{
		t2 = t2 -> next;
	}
	b = t2;
//	printf("%d  %d",a -> data, b-> data);
	while(t3 -> next != NULL)
	{
		if((t3 -> next)-> data == i)
		{
			t3 -> next = b;
		}
		else if((t3 -> next)->data == j)
		{
			t3 -> next = a;
		}
		t3 = t3 -> next;
	}
	
}
int main()
{
	struct node *head = NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	//swap(&head, 3, 4);
	print(head);
	return 0;
}
