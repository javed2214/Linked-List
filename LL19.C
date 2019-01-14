// Program to Create and Display Circular Linked List.

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

void main()
{
	node *head=NULL, *p;
	int n;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createList(n);
	displayList(head);
	
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
			{
				p=p->next;
			}
			p->next=temp;
		}
		temp->next=head;
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
