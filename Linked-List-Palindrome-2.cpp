// Check whether LL is Palindrome or Not without any Extra Space
// Reverse Half of the List and Compare that List with Orignal List

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
			while(p->next)
				p=p->next;
			p->next=temp;
		}
	}
	return head;
}

int countNodes(node *head){

	int count=0;
	while(head){
		count++;
		head=head->next;
	}
	return count;
}

node *reverseList(node *head){

	node *p=head,*t1=NULL,*t2=NULL;
	
	while(p){
		t2=p->next;
		p->next=t1;
		t1=p;
		p=t2;
	}
	return t1;
}

bool compareList(node *p1, node *p2){

	while(p1 and p2){
		if(p1->data!=p2->data) return false;
		p1=p1->next;
		p2=p2->next;
	}
	return true;
}

int main(){

	int a[]={1,2,3,2,1};
	int n=sizeof(a)/sizeof(int);

	node *head=createList(a,n);
	int x=countNodes(head);
	node *p;

	if(x&1){
		p=head;
		x=(x/2);
		while(x--)
			p=p->next;
		p=reverseList(p);
	}
	else{
		p=head;
		x=(x/2)-1;
		while(x--)
			p=p->next;
		p=reverseList(p);
	}

	if(compareList(head,p)) cout<<"Palindrome!";
	else cout<<"Not Palindrome!";

	return 0;
}