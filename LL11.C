// Program to Check whether their are Duplicate Nodes in the List or Not.

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
void duplicateNodes(node *, int);

void main()
{
	int n;
	node *head;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);
	
	head=createList(n);
	displayList(head);

	duplicateNodes(head,n);

	getch();
}
node *createList(int n)
{
	node *head=NULL, *temp=NULL, *p=NULL;
	int i;

	printf("\n");

	for(i=0;i<n;i++)
	{
		temp=(node *)malloc(sizeof(node));
		printf("Enter Data for Node[%d]: ",i+1);
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
void duplicateNodes(node *head, int n)
{
	node *p, *q;
	int flag=0;

	p=head;

	for(p=head;p->next!=NULL;p=p->next)
	{
		q=head;

		for(;q!=NULL;q=q->next)
		{
			if(p!=q)
			{
				if(p->data==q->data)
				{
					flag=1;
					break;
				}
			}
		}
	}
	if(flag==1)
		printf("\n\nThere are Duplicate Nodes in the List");
	else
		printf("\n\nNo Duplicate Nodes");
}