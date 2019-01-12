// Program to Find Center Element of the Linked List.

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
void centerElement(node *, int);

void main()
{
	int n,p,q;
	node *head;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createList(n);
	displayList(head);
	centerElement(head, n);

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
void centerElement(node *head, int n)
{
	int i=1;
	node *p=head;
	if(n%2==0)
	{
		while(i<n/2)
		{
			p=p->next;
			i++;
		}
		printf("Centered Elements: [%d],[%d]",p->data,p->next->data);
	}
	else{
		while(i<=n/2)
		{
			p=p->next;
			i++;
		}
		printf("Centered Element: [%d]",p->data);
	}
}