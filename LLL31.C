// Program to Flatten Binary Search Tree into Linked List.

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct node 
{
	int data;
	struct node *next;
}node;

typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
}tree;

tree *createTree(int,tree *);
void inorderDisplay(tree *);
node *createList(int);
void displayList(node *);
void flatten(tree *);

int main()
{
	int x,choice;
	node *head=NULL;
	tree *root=NULL;

	while(1)
	{
		printf("\n1. Insert Node into BST");
		printf("\n2. Inorder Display");
		printf("\n3. Flatten BST Into Linked List");
		printf("\n4. Exit\n");
		printf("\nEnter your Choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Node Data to Insert: ");
				scanf("%d",&x);
				root=createTree(x,root);
				break;

			case 2:
				printf("\n");
				inorderDisplay(root);
				printf("\n");
				break;

			case 3:
				printf("\n");
				flatten(root);
				printf("\n");
				break;

			case 4:
				exit(0);
		}
	}
}
tree *createTree(int n, tree *root)
{
	if(root==NULL)
	{
		root=(tree *)malloc(sizeof(tree));
		root->data=n;
		root->left=NULL;
		root->right=NULL;
	}
	else if(n < root->data)
		root->left=createTree(n,root->left);
	else if(n > root->data)
		root->right=createTree(n,root->right);
	else
		printf("\nDuplicate Nodes!\n");

	return root;
}
void inorderDisplay(tree *root)
{
	if(root==NULL)
		return;
	else
	{
		inorderDisplay(root->left);
		printf("|%d| ",root->data);
		inorderDisplay(root->right);
	}
}
node *createList(int n)
{
	node *head=NULL,*p=NULL,*temp=NULL;
	int i;

	temp=(node *)malloc(sizeof(node));
	temp->data=n;		
	temp->next=NULL;

	if(head==NULL)
		head=temp;
	else
	{
		p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
	return head;
}
	

void displayList(node *head)
{
	node *p=NULL;
	if(head==NULL)
		printf("List is Empty!");
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
void flatten(tree *root)
{
	node *head;
	if(root==NULL)
		return;
	else
	{
		head=createList(root->data);
		flatten(root->left);
		flatten(root->right);			
	}

	displayList(head);
}
