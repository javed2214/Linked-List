// Program to Remove Duplicate Nodes from Sorted Linked List
// [1,1,2,3,3,4,5,5,6] ==>> [1,2,3,4,5,6]
// Efficient Algorithm

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

		if(head==NULL)
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
	else{
		node *p=head;
		while(p){
			cout<<p->data<<"->";
			p=p->next;
		}
	}
}

node *removeDuplicateNodes(node *head){

	node *p=head,*q;
	while(p and p->next){
		if(p->data==p->next->data){
			q=p->next->next;
			if(q==NULL){
				p->next=NULL;
				break;
			}
			p->next=q;
		}
		if(p->data!=p->next->data)
			p=p->next;
	}
	return head;
}

int main(){

	node *head=NULL;
	int a[]={1,1,1,2,2,3,3,3,4,4,4,5,6,6,6};
	int n=sizeof(a)/sizeof(int);
	head=createList(a,n);
	traverseList(head);
	cout<<"\n";
	head=removeDuplicateNodes(head);
	traverseList(head);

	return 0;
}