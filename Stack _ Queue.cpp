#include <cstdlib>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <iostream>
#define MyInfinite 2147483647


using namespace std;

int heapsize = 0;

struct node{
	int key;
	struct node *next;
	struct node *prev;
};

struct node *InsertInCircularList(struct node *last, int element)
{
	struct node *newNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> key = element;
	if(last == NULL)
		newNode -> next = newNode;
	else
	{
		newNode -> next = last -> next;
		last -> next = newNode;
	}
	last = newNode;
	return last;
}

struct node *DeleteNodeCircularList(struct node *p, struct node *last)
{
	struct node *temp;

	if (last == last -> next)
	{
		free(last);
		last = NULL;
	}
	else
	{
		temp = p -> next;
		p -> next = temp -> next;

		if(temp == last)
			last = p;
		free(temp);
	}
	return last;
}

struct node *InsertInDoubleLinkedCircularList(struct node *last, int element)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));

	newNode -> key = element;
	if(last == NULL)
	{
		newNode -> next = newNode;
		newNode -> prev = newNode;
	}
	else
	{
		newNode -> next = last -> next;
		newNode -> prev = last;

		last -> next = newNode;

		newNode -> next -> prev = newNode;
	}
	last = newNode;
	return last;
}

struct node *DeleteNodeDoubleLinkedCircularList(struct node *actual, struct node *last)
{
	struct node *temp;
	if(last == NULL)
		printf("The double linked circular list is empty.\n");

	else
	{
		if(last == last -> next)
		{
			free(last);
			last = NULL;
		}
		else
		{
			temp = actual -> next;
			actual -> next = temp -> next;
			temp -> next -> prev = actual;
			if(last == temp)
			{
				last = actual;
			}
			free(temp);
		}
	}
	return last;
}

struct node *Enqueue(struct node *last, int element)
{
	return InsertInCircularList(last,element);
}

int Dequeue(struct node **last)
{
	int element = MyInfinite;

	if(*last != NULL)
	{
		element = (*last) -> next -> key;
		*last = DeleteNodeCircularList(*last,*last);
	}
	return element;
}

struct node *Push(struct node *last, int element)
{
	return InsertInDoubleLinkedCircularList(last,element);
}

int Pop(struct node **last)
{
	int element = MyInfinite;

	if (*last!=NULL)
	{
		element = (*last) -> key;
		*last = DeleteNodeDoubleLinkedCircularList((*last)->prev, *last);
	}
	return element;
}
