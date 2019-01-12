// Addition of Node to the Linked List.

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
void addNode(node *, int);

void main()
{
	int n;
	node *head;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createList(n);
	displayList(head);
	addNode(head, n);

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
void addNode(node *head, int n)
{
	int pos,i;
	node *p=NULL, *temp=NULL, *q=NULL;

	printf("\n\nEnter Position of the Node to be Added: ");
	scanf("%d",&pos);

	printf("Enter Data for that Node: ");
	temp=(node *)malloc(sizeof(node));
	scanf("%d",&temp->data);

	p=head;

	if(pos==1)
	{
		temp->next=p;
		head=temp;
	}

	else if(pos==n+1)
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->next=NULL;
	}

	else if(pos>1 && pos<=n)
	{
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=temp;
		temp->next=q;
	}
	else
		printf("\nInvalid Position!\n");

	displayList(head);
}
