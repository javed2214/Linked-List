// Program to Remove Duplicate Nodes From Sorted Linked List
// [1,1,2,2,3,3,3,4,5,5] ==>> [1,2,3,4,5]

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *createNode(int *a, int n){
	node *temp,*head=NULL,*p;
	for(int i=0;i<n;i++){
		temp=(node *)malloc(sizeof(node));
		temp->data=a[i];
		temp->next=NULL;
		if(head==NULL)
			head=temp;
		else{
			p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=temp;
		}
	}
	return head;
}
void traverseList(node *head){
	node *p;
	if(head==NULL)
		printf("List is Empty!");
	else{
		p=head;
		while(p!=NULL){
			printf("[%d]=>",p->data);
			p=p->next;
		}
	}
}
node *removeDuplicates(node *head){
	node *p=head,*s,*newHead=NULL;
	while(p->next){
		if(p->data!=p->next->data){
			node *temp=(node *)malloc(sizeof(node));
			temp->data=p->data;
			temp->next=NULL;

			if(newHead==NULL)
				newHead=temp;
			else{
				s=newHead;
				while(s->next)
					s=s->next;
				s->next=temp;
			}
		}
		p=p->next;
	}
	node *temp=(node *)malloc(sizeof(node));
	temp->data=p->data;
	temp->next=NULL;
	s=newHead;
	while(s->next)
		s=s->next;
	s->next=temp;

	return newHead;
}
int main(){

	node *head=NULL;
	int a[]={1,1,1,2,2,2,2,2,3,4,5,5,5};
	int n=sizeof(a)/sizeof(int);
	head=createNode(a,n);
	traverseList(head);
	cout<<"\n";
	head=removeDuplicates(head);
	traverseList(head);

	return 0;
}
