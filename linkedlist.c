#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node * next;
}link;
void add_begin(link **h, int v)
{
	link *n = (link*)malloc(sizeof(link));
	n->data = v;
	n->next = *h;
	*h = n;
}
void add_end(link **h, int v)
{
	if(*h == NULL)
	{
		add_begin(h, v);
	}
	else
	{
		link *p = *h;
		while(p->next != NULL)
		{
			p = p->next;
		}
		link *n = (link*)malloc(sizeof(link));
		n->data = v;
		n->next = NULL;
		p->next = n;
	}
}
void add_at_pos(link **h, int v, int pos)
{
	int i = 0;
	link *curr = *h;
	if(pos == 1)
	{
		add_begin(h,v);
	}
	else
	{
		while( i < pos-1 && curr!=NULL)
		{
			curr = curr->next;
			i++;
		}
		if( curr != NULL )
		{
			link *n = (link*)malloc(sizeof(link));
			n->data = v;
			n->next = curr->next;
			curr->next = n;
		}
	}
}
void print(link *h)
{
	while( h != NULL)
	{
		printf("%d", h->data);
		h = h->next;
	}
}
int delete_begin(link **h)
{
	if(*h == NULL)
	{
		printf("list is empty\n");
		return -1;
	}
	
	
	link *temp = *h;
	*h = (*h) -> next;
	int x = temp -> data;
	free(temp);
	temp = NULL;
	return x;
	
}
int delete_end(link **h)
{
	int x;
	if(*h == NULL)
	{
		printf("list is empty\n");
		return -1;
	}
	link *temp = *h;
	link *temp1 = NULL;
    if( (*h) -> next == NULL)
	{
		*h = NULL;
		x = temp -> data;
		free(temp);
		temp = NULL;
	}
	else
	{

		while(((temp->next)->next) != NULL)
			{
				temp = temp -> next;
			}
		temp1 = temp -> next;
		temp -> next = NULL;
		 x = temp1 -> data;
		free(temp1);
		temp1 = NULL;
	}
	return x;
}
int delete_at_pos(link **h, int pos)
{
	int i = 1;
	int x;
	link *curr = *h;
	link *temp = NULL;
	if( *h == NULL)
	{
		printf("list is empty\n"); return -1;		
	}
	if( (*h) -> next == NULL)
	{
		x = delete_end(h);
	}
	while( i < pos -1 && curr != NULL)
	{
		curr = curr -> next; i++;
	}
	if( curr != NULL && curr -> next != NULL)
	{
		temp = curr -> next;
		curr-> next = temp -> next;
		x = temp -> data;
		free(temp);
		temp = NULL;
	}
	return x;
}
void reverse(link **h)
{
	link *prev = NULL;
	link *curr = *h;
	link *next = NULL;
	while( curr != NULL)
	{
		next  = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*h = prev;
	// DOUBT DOUBT  where do we exactly use free and why is free valid when malloc is not used free(next); next = NULL;
	// this is because local variables are prev and curr which have value from stack and dynamic variables have space in
	//heap so the local ones r deleted automatically.
}
int count(link *h)
{
	int x = 0;
	while( h != NULL )
	{
		x++;
		h = h -> next;
	}
	return x;
}
int middle(link *h)
{
	link *fast = h;
	link *slow = h;
	while( fast -> next != NULL && (fast -> next) -> next != NULL )
	{
		slow = slow -> next;
		fast = (fast -> next) -> next;
	}
	return (slow -> data);
	
}
int search(link *h, int v)
{
	int x = 0;
	while( h != NULL)
	{	
		x++;
		if( h -> data == v )
		{
			return x; 
		} 
		h = h -> next;
	}	
	return -1;
}
void reverse_pair(link **h)
{
	link **current = h;     //to store the add of previous first
	link *first = *h;
	link *second = first ->next;
	while(first -> next != NULL && second -> next != NULL)
	{
		first -> next = second -> next;
		second -> next = first;
		*current = second;
		current = &(first -> next);
		first = first -> next;
		second = first -> next;
	}  
}
link* reverse_recursive(link *h)
{
	link *first = h;
	link *second = first -> next;
	if(second == NULL)
	{
		return first; 
	}
	else
	{
		link *he = reverse_recursive(second);
		second -> next = first;
		first -> next = NULL;
		return he;
	}
}
void zig_zag(link *h)
{
 	link *first = h;
	link *second = h -> next;
	while(first != NULL)
	{
		printf("%d",first -> data);
		first = (first -> next) -> next;
	}
	while( second != NULL)
	{
		printf("%d",second -> data);
		if( second -> next != NULL && (second -> next) -> next != NULL)
			second = (second -> next) -> next;
		else
			break;
	}
			
}
void union_of_list(link *h)
{
	
}
int main()
{
	int x = 0;
	link *head = NULL;
	add_begin(&head, 10); print(head); printf("\t%d\n",x);
    add_end(&head, 20); print(head); printf("\t%d\n",x);
	add_at_pos(&head, 30, 1); print(head); printf("\t%d\n",x);
	add_at_pos(&head, 40, 2); print(head); printf("\t%d\n",x);
	add_at_pos(&head, 50, 3); print(head); printf("\t%d\n",x);	
	add_at_pos(&head, 60, 3); print(head); printf("\t%d\n",x);
	x = count(head); print(head); printf("\t%d\n",x);
	x = search(head, 10); print(head); printf("\t%d\n",x);
	x = middle(head); print(head); printf("\t%d\n",x);
	reverse(&head); print(head); printf("\t%d\n",x);
	head = reverse_recursive(head); print(head); printf("\t%d\n",x);
	reverse_pair(&head); print(head); printf("\t%d\n",x);
//	union_of_list(head); // take two link list and find their union
	zig_zag(head); printf("\n"); // (1,3,5,4,7) -> (1,5,7,3,4) 
	// to find if there is a loop in linked list. loop can exsist anywhere.
	x = delete_begin(&head);print(head); printf("\t%d\n",x);
	x = delete_end(&head); print(head); printf("\t%d\n",x);
	x = delete_at_pos(&head, 2); print(head); printf("\t%d\n",x);
	x = delete_at_pos(&head, 1); print(head); printf("\t%d\n",x);
	return 0;
}
