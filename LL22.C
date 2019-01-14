// Program to Implement Double Linked List.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int);
void displayList(node *);

void main()
{
	node *head=NULL;
	int n,choice;

	while(1)
	{
		printf("\n1. Press 1 to Create Node");
		printf("\n2. Traverse List");
		printf("\n3. Exit");

		printf("\n\nEnter your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Number of Nodes: ");
				scanf("%d",&n);
				head=createNode(n);
				break;

			case 2:
				printf("\n");
				displayList(head);
				printf("\n");
				break;

			case 3:
				exit(1);
		}
	}
}
node *createNode(int n)
{
	node *temp, *p, *head=NULL;
	int i;

	printf("\n");

	for(i=0;i<n;i++)
	{
		printf("Enter Data for Node[%d]: ",i+1);
		temp=(node *)malloc(sizeof(node));
		scanf("%d",&temp->data);

		temp->left=NULL;
		temp->right=NULL;

		if(head==NULL)
			head=temp;

		else
		{
			p=head;

			while(p->right!=NULL)
				p=p->right;

			p->right=temp;
			temp->left=p;
			temp->right=NULL;
		}
	}
	return head;
}	
void displayList(node *head)
{
	node *p;
	p=head;

	if(head==NULL)
		printf("\nList is Empty!\n");
	else
	{
		while(p!=NULL)
		{
			printf("<=[%d]=>",p->data);
			p=p->right;
		}
	}
}