// Find Pairs With Given Sum in Doubly Linked List.

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n);
void displayList(node *head);
void sumPair(node *head, int n);

int main()
{
	int n;
	node *head=NULL;

	printf("Enter Number of Nodes: ");
	scanf("%d",&n);
	head=createNode(n);
	printf("\n");
	displayList(head);
	printf("\n");
	sumPair(head,n);

	return 0;
}
node *createNode(int n)
{
	int i;
	node *temp=NULL;
	node *p=NULL, *head=NULL;
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
		printf("List is Empty!");
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
void sumPair(node *head, int n)
{
	int sum,arr[1000],i,flag=0,j,k=0,count=0,x[100],y[100],s=0;
	node *p;
	p=head;
	printf("\nEnter Number: ");
	scanf("%d",&sum);

	for(i=0;i<n;i++)
	{
		arr[i]=p->data;
		p=p->right;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(sum==arr[i]+arr[j])
			{
				x[k]=i;y[k]=j;
				for(s=0;s<=k;s++)
				{
					if(x[s]==j && y[s]==i)
						count--;
				}
				count++;
				flag=1;
				k++;	
			}
		}
	}
	i=0;
	if(flag==1)
	{
		while(count--)
		{
			printf("Pair: [%d] and [%d]\n",arr[x[i]],arr[y[i]]);
			i++;
		}
	}
	if(flag!=1)
		printf("\nPair Not Found!\n");
}
