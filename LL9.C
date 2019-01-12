// Program to Sort Linked List in Ascending Order.

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
void sortList(node *, int);

void main()
{
	int n,p,q;
	node *head;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createList(n);
	displayList(head);
	sortList(head, n);

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
void sortList(node *head, int n)
{
	int temp;
	node *i , *j;
	
	i=head;


	for(i=head;i!=NULL;i=i->next)
	{
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(i->data > j->data)
			{
				temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}

	printf("\n\nSorted Linked List: \n");

	displayList(head);
}