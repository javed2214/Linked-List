// Program to Insert Node in Double Linked List.

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
node *insertNode(node *, int);

void main()
{
	node *head=NULL;
	int n,choice;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createNode(n);
	displayList(head);
	head=insertNode(head,n);
	displayList(head);

	getch();
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

	printf("\n");

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
node *insertNode(node *head, int n)
{
	node *p, *temp, *q;
	int pos, i;

	p=head;

	printf("\n\nEnter Node Data to Insert: ");
	temp=(node *)malloc(sizeof(node));
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;

	printf("Enter Position: ");
	scanf("%d",&pos);

	if(pos==1)
	{
		temp->right=p;
		p->left=temp;
		head=temp;
	}
	else if(pos==n+1)
	{
		while(p->right!=NULL)
			p=p->right;

		p->right=temp;
		temp->left=p;
		temp->right=NULL;
	}
	else if(pos>1 && pos<=n)
	{
		for(i=1;i<pos-1;i++)
			p=p->right;

		q=p->right;
		p->right=temp;
		temp->left=p;
		temp->right=q;
		q->left=temp;
	}
	else
	{
		printf("\nInvalid Position!");
		delay(1000);
		exit(1);
	}

	return head;
}