// Program to Remove nth Node From End of the Linked List

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

node *removeNthNode(node *head, int n){

	node *prev, *cur;
	prev=cur=head;
	
	while(n--)
		cur=cur->next;

	if(cur==NULL)
		return head->next;

	while(cur->next!=NULL){
		cur=cur->next;
		prev=prev->next;
	}
	prev->next=prev->next->next;

	return head;	
}

int main(){

	node *head=NULL;
	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(int);
	head=createList(a,n);
	traverseList(head);
	int k;cin>>k;
	head=removeNthNode(head,k);
	cout<<"\n";
	traverseList(head);

	return 0;
}