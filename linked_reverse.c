#include<stdio.h>
#include<stdlib.h>
typedef struct link{
	int data;
	struct linked *next;
}linked;
void add_begin(linked **h, int i)
{
	linked *t = (linked*)malloc(sizeof(linked));
	t -> data = i;
	t -> next = (*h) -> next;
	*h = t;
}
void add_end(linked **h, int i)
{
	if(*h == NULL)
	{
		add_begin(h, i);
	}
	else
	{
		linked *t1 = *h;
		while(t1 -> next != NULL)
		{
			t1 = t1 -> next;
		}	
		linked *t = (linked*)malloc(sizeof(linked));
	t -> data = i;
		t -> next = NULL;
		t1 -> next = t;
	}	
}
void add_at_pos(linked **h, int i, int pos)
{
	linked *t = (linked*)malloc(sizeof(linked));
	linked *t1 = *h;
	int j = 0;
	while( j < (pos - 1) && t1 != NULL)
	{
		t1 = t1 -> next;
		j++;
	}
	if(t1 != NULL)
	{
		t -> data = i;
		t -> next = t1 -> next;
		t1 -> next = t;
	}
}
void reverse(linked **h)
{
	linked *prev = NULL;
	linked *curr = *h;
	linked *nex = NULL;
	while(curr != NULL)
	{
		nex = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = nex;
	}
	*h = prev;
}
linked* reverse_recursive(linked **h)
{
	linked *first = *h;
	linked *second = first -> next;
	linked *he;
	if(second -> next == NULL)
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
int delete_begin(linked **h)
{
	linked *t = (*h) -> next;
	int x = (*h) -> data;
	*h = t;
	t = NULL;
	free(t);
	return x;
}
int delete_end(linked **h)
{
	linked *t = (*h) -> next;
	if(t == NULL)
	{
		printf("list empty");
		return -1;
	}
	while( (t -> next != NULL) && ((t -> next)->next) != NULL)
	{
		t = t -> next;
	}
	linked *t1 = t;
	int x = t1 -> data;
	t -> next = NULL;
	t1 = NULL;
	free(t1);
	return x;
}
int delete_pos(linked **h, int pos)
{
	if(pos == 0)
		delete_begin(h);
	else
	{
		int i = 0, x = 0;
		linked *t = *h;
		while(i < (pos -1) && t -> next != NULL)
		{
			t = t -> next;
			i++;
		}
		if( t != NULL)
		{
			x = t -> data;
			t -> next = (t -> next)->next;
			t = NULL;
			free(t);
		}
		return x;
	}
}
int main()
{
	linked *h = NULL;
	add_begin(&h,10);
	add_begin(&h,20);
	add_end(&h,30);
	add_end(&h,40);
	add_at_pos(&h,20, 2);
	add_at_pos(&h,25, 3);
	h = reverse_recursive(&h);
	reverse(&h);
	printf("%d",delete_begin(&h));
	printf("%d", delete_end(&h));
	printf("%d", delete_pos(&h, 2));
	return 0;
}
	
		
