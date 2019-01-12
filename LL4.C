// Search any Particular Node in the Linked List.

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
void searchNode(node *);

void main()
{
	int n;
	node *head;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createList(n);
	displayList(head);
	searchNode(head);

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
void searchNode(node *head)
{
	node *p;
	int d,count=1,flag=0;

	p=head;

	printf("\n\nEnter Node Data you want to Search: ");
	scanf("%d",&d);

	while(p!=NULL)
	{
		if(p->data==d)
		{
			flag=1;
			break;
		}
		p=p->next;
		count++;		
	}
	if(flag==0)
		printf("\nNode not Found!");
	else
		printf("\nNode found at Position %d",count);
}
