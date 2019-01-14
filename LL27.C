// Deletion of Alternate Nodes From Doubly Linked List.

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int);
void displayList(node *);
node *deleteAlternateNode(node *,int);

int main()
{
	node *head=NULL;
	int n;
	printf("Enter Number of Nodes you want to Create: ");
	scanf("%d",&n);
	head=createNode(n);
	printf("\n");
	displayList(head);
	printf("\n\nAfter Alternate Nodes Deletion: \n\n");
	head=deleteAlternateNode(head,n);
	displayList(head);
	printf("\n");

	return 0;
}
node *createNode(int n)
{
	node *p=NULL, *temp=NULL, *head=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		temp=(node *)malloc(sizeof(node));
		printf("Enter Data for Node[%d]: ",i+1);
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
node *deleteAlternateNode(node *head, int n)
{
	node *temp,*p,*q,*s;
	p=s=head;
	if(n%2==0)
	{
		while(p->right!=NULL)
		{
			q=p->right;
			s=s->right;
			p->right=s->right;
			if(s->right!=NULL)
				s=s->right;
			if(s!=NULL)
				s->left=p;
			if(p->right!=NULL)
				p=p->right;
			free(q);
		}
	}
	if(n%2!=0)
	{
		while(p->right!=NULL && s!=NULL)
		{
			q=p->right;
			s=s->right;
			p->right=s->right;
			s=s->right;
			if(s!=NULL)
				s->left=p;
			p=p->right;
			free(q);
		}
	}
	
	return head;
}