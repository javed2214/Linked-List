// Deletion of Node from the Linked List.

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
node *deleteNode(node *, int, int);

void main()
{
	int n,i,choice,pos;
	node *head;

	clrscr();

	while(1)
	{
		printf("\n1. Create List");
		printf("\n2. Display List");
		printf("\n3. Delete Node");
		printf("\n4. Exit");

		printf("\n\nEnter your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Number of Nodes youwant to Create: ");
				scanf("%d",&n);
				head=createList(n);
				break;

			case 2:
				printf("\n");
				displayList(head);
				printf("\n");
				break;

			case 3:
				printf("\nEnter Node position you want to Delete: ");
				scanf("%d",&pos);
				head=deleteNode(head, n, pos);
				break;

			case 4:
				exit(1);
		}
	}
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
node *deleteNode(node *head, int n, int pos)
{
	node *p=NULL, *temp=NULL, *q=NULL;
	int i;
	p=head;

	if(pos==1)
	{
		temp=p->next;
		free(p);
		head=temp;

		printf("\nNode Deleted!\n");
	}
	else if(pos==n)
	{
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		temp=p->next;
		free(temp);
		p->next=NULL;
		printf("\nNode Deleted!\n");
	}
	else if(pos>1 && pos<n)
	{
		for(i=1;i<pos-1;i++)
		{
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		free(q);
		printf("\nNode Deleted!\n");
	}
	else
		printf("\nInvalid Node!\n");

	return head;
}
