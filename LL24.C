// Program to Delete Specific Node from a Double Linked List.

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
node *deleteNode(node *, int);

void main()
{
	node *head=NULL;
	int n,choice;

	clrscr();

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);

	head=createNode(n);
	displayList(head);
	head=deleteNode(head,n);
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
node *deleteNode(node *head, int n)
{
	node *p, *q, *r;
	int pos, i;
	p=head;

	printf("\n\nEnter Position of the Node to Delete: ");
	scanf("%d",&pos);

	if(pos==1)
	{
		q=p->right;
		free(p);
		q->left=NULL;
		head=q;
	}
	else if(pos==n)
	{
		while(p->right->right!=NULL)
			p=p->right;

		q=p->right;
		p->right=NULL;
		free(q);
	}
	else if(pos>1 && pos<n)
	{
		q=head;

		for(i=1;i<pos-1;i++)
		{	
			p=p->right;
			q=q->right;
		}
		r=p->right;
		q=q->right->right;
		p->right=q;
		q->left=p;
		free(r);
	}

	return head;
}