// Program to Remove all Occurrence of Given Elements from Linked List
// [1,6,4,5,9,6,6,3] k=6 ==>> [1,4,5,9,3]  (Remove all Occurrence of '6')
// Two Pointer Algorithm
// https://leetcode.com/problems/remove-linked-list-elements/

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

node *removeElements(node *head, int k){

	while(head and head->data==k)
		head=head->next;
	
	if(head==NULL)
		return head;
	
	node *prev,*curr;
	prev=head;
	curr=head->next;
	
	while(curr){
		
		if(curr->data==k)
			prev->next=curr->next;
		else
			prev=curr;
		
		curr=curr->next;
	}
	return head;
}

int main(){

	node *head=NULL;
	int a[]={6,6,1,2,6,6,5,7,6,8};
	int n=sizeof(a)/sizeof(int);
	int k=6;
	head=createList(a,n);
	traverseList(head);
	cout<<"\n";
	head=removeElements(head,k);
	traverseList(head);

	return 0;
}