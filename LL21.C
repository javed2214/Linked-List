// Program to Delete Node from a Circular Linked List.

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
void deleteNode(node *, int n);

void main()
{
	node *head=NULL, *p;
	int n;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createList(n);
	displayList(head);
	deleteNode(head, n);

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
		{
			head=temp;
			temp->next=head;
		}

		else
		{
			p=head;

			while(p->next!=head)
				p=p->next;

			p->next=temp;
			temp->next=head;
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
		do
		{
			printf("[%d]=>",p->data);
			p=p->next;

		}while(p!=head);
	}
}
void deleteNode(node *head, int n)
{
	node *p, *q, *r;
	int pos,i;

	p=head;

	printf("\n\nEnter Position of Node you want to Delete: ");
	scanf("%d",&pos);

	if(pos==1)
	{
		temp=p->next;
		while(q->next!=head)
			q=q->next;
		q->next=temp;
		head=temp;
		free(p);
	}
	else if(pos==n)
	{
		while(p->next!=head)
			p=p->next;

		q=p->next;
		p->next=head;
		free(q);	
	}
	else if(pos>1 && pos<=n)
	{
		for(i=1;i<pos-1;i++)
			p=p->next;

		q=p->next;
		p->next=q->next;
		free(q);
	}
	printf("\nNode Deleted:");
	displayList(head);
}