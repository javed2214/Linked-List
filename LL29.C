// Program to Reverse Doubly Linked List.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int);
void displayList(node *);
node *reverseList(node *);

int main()
{
	int n;
	node *head=NULL;

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);
	head=createNode(n);
	printf("\n");
	displayList(head);
	printf("\nReversed List: \n");
	head=reverseList(head);
	displayList(head);
	printf("\n");

	return 0;
}
node *createNode(int n)
{
	node *temp,*p,*head=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		temp=(node *)malloc(sizeof(node *));
		printf("Enter Data at Node[%d]: ",i+1);
		scanf("%d",&temp->data);
		temp->right=NULL;
		temp->left=NULL;

		if(head==NULL)
			head=temp;
		else
		{
			p=head;
			while(p->right!=NULL)
				p=p->right;
			p->right=temp;
			temp->left=p;
		}
	}
	return head;
}
void displayList(node *head)
{
	node *p;
	if(head==NULL)
		printf("List is Empty!\n");
	else
	{
		p=head;
		while(p!=NULL)
		{
			printf("<=[%d]=>",p->data);
			p=p->right;
		}
	}
}
node *reverseList(node *head)
{
	node *p,*temp;
	p=head;
	
	while(p!=NULL)
	{
		if(p->right==NULL)
			head=p;
		temp=p->right;
		p->right=p->left;
		p->left=temp;
		p=temp;
	}
		
	return head;
}