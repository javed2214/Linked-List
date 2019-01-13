// Program to Count Number of times a given Node Data occurs in the Linked List.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *createList(int);
void displayList(node *);
node *countNode(node *);

void main()
{
	node *head=NULL, *p;
	int n;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createList(n);
	displayList(head);
	p=countNode(head);

	getch();
}
node *createList(int n)
{
	node *p, *temp, *head=NULL;
	int i;

	printf("\n");

	for(i=0;i<n;i++)
	{
		temp=(node *)malloc(sizeof(node));
		printf("Enter Data for Node[%d]: ", i+1);
		scanf("%d",&temp->data);

		temp->next=NULL;

		if(head==NULL)
			head=temp;
		else
		{
			p=head;

			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=temp;
		}
	}
	return head;
}
void displayList(node *head)
{
	node *p;

	printf("\n");

	if(head==NULL)
		printf("\nList is Empty!");
	else
	{
		p=head;

		while(p!=NULL)
		{
			printf("[%d]=>",p->data);
			p=p->next;
		}
	}
}
node *countNode(node *head)
{
	node *p;
	int d,count=0;

	p=head;

	printf("\n\nEnter Node Data you want to Count: ");
	scanf("%d",&d);

	while(p!=NULL)
	{
		if(d==p->data)
			count++;
		p=p->next;
	}
	printf("\n%d occurs %d Times",d,count);
}