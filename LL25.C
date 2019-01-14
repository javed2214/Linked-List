// Program to Check Whether the Two Linked Lists are Identical or Not.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node *createNode(int);
void displayList(node *);
int compareLists(node *, int, node *, int);

void main()
{
	int n1,n2,flag;
	node *head1=NULL;
	node *head2=NULL;

	clrscr();

	printf("Number of Nodes in List 1: ");
	scanf("%d",&n1);
	head1=createNode(n1);
	displayList(head1);

	printf("\n\nNumber of Nodes in List 2: ");
	scanf("%d",&n2);
	head2=createNode(n2);
	displayList(head2);

	flag=compareLists(head1, n1, head2, n2);

	if(flag==1)
		printf("\n\nLists Are Identical");
	else if(flag==0)
		printf("\n\nLists Are Not Identical");
	else
		printf("\n\nBoth Lists are Empty");

	getch();
}
node *createNode(int n)
{
	int i=0;
	node *p=NULL, *temp=NULL, *head=NULL;
	printf("\n");
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
	return head;
}
void displayList(node *head)
{
	node *p;
	printf("\n");

	if(head==NULL)
		printf("List is Empty\n");

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
int compareLists(node *head1, int n1, node *head2, int n2)
{
	node *p1, *p2;
	int flag=0;

	if(n1!=n2)
		return 0;

	else if(head1==NULL && head2==NULL)
		return 2;

	else if(head1==NULL || head2==NULL)
		return 0;

	else if(n1==n2)
	{
		p1=head1;
		p2=head2;

		while(p1->next!=NULL)
		{
			if(p1->data!=p2->data)
			{
				flag=1;
				return 0;
			}
			p1=p1->next;
			p2=p2->next;
		}
		if(flag==0)
			return 1;
	}
}