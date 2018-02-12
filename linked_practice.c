#include<stdio.h>
#include<stdlib.h>
typedef struct list{
	int data;
	struct list *next;
}li;
void print(li **h)
{
	li *t = *h;
	while(t != NULL)
	{
		printf("%d ", t->data);
		t = t -> next;
	}
	printf("\n");
}
void add_begin(li **h, int i)
{
	li *n = (li*)malloc(sizeof(li));
	n -> data = i;
	n -> next = *h;
	*h = n;
	print(h);
}
void add_end(li **h, int i)
{
	if( *h == NULL)
		add_begin(h, i);
	else
	{
	li *t = *h;
	while(t -> next != NULL)
	{
		t = t -> next;
	}
	li *n = (li*)malloc(sizeof(li));
	n -> data = i;
	n -> next = NULL;
	t -> next  = n;
	}
	print(h);
}
void add_pos(li **h, int i, int pos)
{
	li *t1 = *h;
	int j = 0;
	while(j < (pos - 1) && t1 != NULL)
	{
		t1 = t1 -> next;
		j++;
	}
	li *t2;
	if(t1 != NULL)
	{
		li *n = (li*)malloc(sizeof(li));
		n -> data = i;
		n -> next = t1 -> next;
		t1 -> next = n;
	}
	else
	{
		printf("invalid position\n");
	}
	print(h);
}
void reverse(li **h)
{
	li *prev = NULL;
	li *curr = *h;
	li *nex = NULL;
	while( curr != NULL)
	{
		nex = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = nex;
	}
	*h = prev;
	print(h);
}
li* reverse_recursive(li **h)
{
	li *first = *h;
	li *second = first -> next;
	li *he;
	if( second == NULL)
	{
		return first;
	}
	else
	{
		he = reverse_recursive(&second);
		second -> next = first;
		first -> next = NULL;
	}
	return he;
}
void sort( li **h)
{
}
int delete_begin(li **h)
{
	int t = (*h) -> data;
	li *t1 = (*h) -> next;
	*h = t1;
	t1 = NULL;
	free(t1);
	return t;
}
int delete_end(li **h)
{
	li *t1 = *h;
	while( t1 -> next != NULL && (t1 -> next) -> next != NULL)
	{
		t1 = t1 -> next;
	}
	int t = (t1 -> next) -> data;
	li *t2 = t1 -> next;
	t2 = NULL;
	free(t2);
	t1 -> next = NULL;
	return t;
}
int delete_pos(li **h, int pos)
{
	int j = 0, x;
	li *t1 = *h;
	while( j < (pos - 1) && (t1 != NULL)) 
	{
		t1 = t1 -> next;
		j++;
	}
	if(t1 != NULL && t1 -> next != NULL)
	{
		li *t2 = t1 -> next;
		x = t2 -> data;
		t1 -> next = t2 -> next;
		t2 = NULL;
		free(t2);
		return x;
	}
}			 
int main()
{
	li *h = NULL;
	add_begin(&h, 10);
	add_end(&h, 20);
	add_pos(&h, 30, 1);
	add_pos(&h, 40, 3);
	add_pos(&h, 50, 7);
	reverse(&h);
	h = reverse_recursive(&h); print(&h);
//	sort(&h);
	int x;
	x = delete_begin(&h); printf("%d\n", x);
	x = delete_end(&h); printf("%d\n", x);
	x = delete_pos(&h, 1); printf("%d\n", x);
	return 0;
}
