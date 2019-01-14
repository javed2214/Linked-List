// Program to Rearrange Linked List in Zig-Zag Manner.

#include<stdio.h>
#include<stdlib.h>
#define swap(a,b) a^=b^=a^=b

typedef struct node
{
	int data;
	struct node *next;
}node;

node *createNode(int);
void displayList(node *);
void zigZag(node *);

int main()
{
	node *head=NULL;
	int n;
	printf("Enter Number of Nodes: ");
	scanf("%d",&n);
	head=createNode(n);
	printf("\nNormal List\n");
	displayList(head);
	printf("\n");
	zigZag(head);

	return 0;
}
node *createNode(int n)
{
	node *temp=NULL,*p=NULL,*head=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		printf("Enter Data for Node[%d]: ",i+1);
		temp=(node *)malloc(sizeof(node));
		scanf("%d",&temp->data);
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
	}
	return  head;
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
void zigZag(node *head)
{
	node *p;
	p=head;
	p=p->next;
	while(p->next->next!=NULL)
	{
		swap(p->data,p->next->data);
		p=p->next;
	}
	printf("Zig-Zag List:\n");
	displayList(head);
}