// Program to Find Intersection of Two Linked Lists.

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
void intersection(node *, int, node *, int);

void main()
{
	int n1,n2;
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

	intersection(head1,n1,head2,n2);

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
void intersection(node *head1, int n1, node *head2, int n2)
{
	node *r, *s, *p;
	int x, arr[200], i=0, count=0;

	x=n1 > n2 ? n1 : n2;

	if(x==n1)
	{
		r=head1;
		s=head2;
		p=head2;
	}
	else
	{
		r=head2;
		s=head1;
		p=head1;
	}
	while(r!=NULL)
	{
		while(s!=NULL)
		{
			if(r->data==s->data)
			{
				arr[i]=r->data;
				count++;
				i++;
			}
			s=s->next;
		}
		if(s==NULL)
			s=p;
		r=r->next;
	}
	if(count==0)
		printf("\n\nNo Common Nodes!");
	else
	{
		printf("\n\nNodes Which are Common to Both the Lists: \n");
		for(i=0;i<count;i++)
			printf("%d\n",arr[i]);
	}
}