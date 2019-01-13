// Program to Add Node in a Sorted Linked List.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *createList(int);
void displayList(node *);
node *sortedList(node *);
void addNode(node *);

void main()
{
	int n;
	node *head=NULL;

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createList(n);
	displayList(head);
	head=sortedList(head);
	addNode(head);
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
node *sortedList(node *head)
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
	return head;
}
void addNode(node *head)
{
	node *p, *q, *temp;
	int count=0,flag=0;

	printf("\n\nEnter Node you want to Add: ");
	temp=(node *)malloc(sizeof(node));
	scanf("%d",&temp->data);
	p=head;
	if(temp->data <= p->data)
	{
		temp->next=p;
		head=temp;
		flag=1;
	}

	p=head;
	while(p->next!=NULL)
		p=p->next;
	if(temp->data >= p->data)
	{
		flag=1;
		p->next=temp;
		temp->next=NULL;
	}

	if(flag!=1)
	{
		p=head;
		while(p->next!=NULL)
		{
			if(temp->data > p->data)
				count++;
			else
				break;
			p=p->next;
		}
		p=head;
		count--;
		while(count--)
			p=p->next;
		q=p->next;
		p->next=temp;
		temp->next=q;
	}
	displayList(head);
	printf("\n");
}