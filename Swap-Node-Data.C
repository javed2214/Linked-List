// Program to Swap Data of two Nodes.

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
void swapData(node *, int, int);

void main()
{
	int n,p,q;
	node *head;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createList(n);
	displayList(head);

	printf("\n\nEnter Node Position you want to Swap: ");
	scanf("%d",&p);
	printf("\nEnter Node Position by which you want to Swap: ");
	scanf("%d",&q);

	swapData(head, p, q);

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
void swapData(node *head, int p, int q)
{
	node *m, *n;
	int temp, i;
	m=n=head;

	for(i=1;i<p;i++)
		m=m->next;

	for(i=1;i<q;i++)
		n=n->next;

	temp=m->data;
	m->data=n->data;
	n->data=temp;

	printf("\nNode Data Swapped!\n");

	displayList(head);
}
