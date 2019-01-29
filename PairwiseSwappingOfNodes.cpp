// Pairwise Swapping of Nodes
// [1,2,3,4,5,6] ==>> [2,1,4,3,6,5]

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

node *swapPairWise(node *head){

	node *new_head=head->next;
	node *temp,*p,*q;
	p=head;

	while(1){

		q=p->next;
		temp=q->next;
		q->next=p;

		if(!temp){
			p->next=NULL;
			break;
		}
		if(!temp->next){
			p->next=temp;
			break;
		}

		p->next=temp->next;
		p=temp;
	}
	return new_head;
}

int main(){

	node *head=NULL;
	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(int);
	head=createList(a,n);
	traverseList(head);
	head=swapPairWise(head);
	cout<<"\n";
	traverseList(head);

	return 0;
}
