// Program to Reverse Linked List Recursively
// Two Methods

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

		if(head==NULL) head=temp;
		else{
			p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=temp;
		}
	}
	return head;
}

// ----------------- Method 1 ------------------------

node *newHead=NULL;
void reverseListt(node *head){

	if(head->next==NULL){
		newHead=head;
		return;
	}
	reverseListt(head->next);
	node *temp=head->next;
	temp->next=head;
	head->next=NULL;
}


// ----------------- Method 2 ------------------------

node *reverseList(node *head){

	if(head==NULL or head->next==NULL) return head;
	node *temp=reverseList(head->next);
	head->next->next=head;
	head->next=NULL;
	return temp;
}

void printList(node *head){

	while(head){
		cout<<head->data<<"=>";
		head=head->next;
	}
}

int main(){

	int a[]={1,2,3,4,5,6,7,8,9};
	int n=sizeof(a)/sizeof(int);

	node *head=createList(a,n);
	head=reverseList(head);

	printList(head);
	cout<<"\n";

	return 0;
}