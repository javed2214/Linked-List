// Program to find nth Node from end in the List.

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
void nthNode(node *, int);

void main()
{
	node *head=NULL;
	int n;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createList(n);
	displayList(head);
	nthNode(head, n);

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
void nthNode(node *head, int n)
{
	node *p, *temp;
	int d;
	p=head;

	printf("\n\nEnter nth Node from the End: ");
	scanf("%d",&d);

	while(n-d)
	{
		p=p->next;
		d++;
	}
	printf("\nnth Node from the End: %d",p->data);
}
