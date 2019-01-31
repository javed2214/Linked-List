// Program to Merge Two Linked List Recursively

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *createList(int *a, int n){

	node *head=NULL,*p;
	for(int i=0;i<n;i++){
		node *temp=(node *)malloc(sizeof(node));
		temp->data=a[i];
		temp->next=NULL;

		if(!head)
			head=temp;
		else{
			p=head;
			while(p->next)
				p=p->next;
			p->next=temp;
		}
	}
	return head;
}

void traverseList(node *head){

	if(!head) return;
	node *p=head;
	while(p){
		cout<<p->data<<"->";
		p=p->next;
	}
}

node *mergeList(node *head1, node *head2){

	node *res=NULL;
	if(head1==NULL) return head2;
	else if(head2==NULL) return head1;
	if(head1->data<=head2->data){
		res=head1;
		res->next=mergeList(head1->next,head2);
	}
	else{
		res=head2;
		res->next=mergeList(head1,head2->next);
	}
	return res;
}

int main(){

	node *head=NULL,*head1=NULL,*head2=NULL;
	int a[]={1,3,5};
	int n1=sizeof(a)/sizeof(int);
	int b[]={2,4,6};
	int n2=sizeof(b)/sizeof(int);
	head1=createList(a,n1);
	traverseList(head1);
	cout<<"\n";
	head2=createList(b,n2);
	traverseList(head2);
	cout<<"\n";
	head=mergeList(head1,head2);
	traverseList(head);

	return 0;
}