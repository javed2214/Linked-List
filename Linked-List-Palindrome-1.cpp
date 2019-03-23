// Push each Elements of Linked List into the Stack
// Pop each Element one by one and Compare it with Linked List

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

bool isPalindrome(node *head){

	node *p=head;
	stack <int> S;

	while(p){
		S.push(p->data);
		p=p->next;
	}
	p=head;
	while(!S.empty()){
		if(p->data!=S.top())
			return false;
		S.pop();
		p=p->next;
	}
	return true;
}

int main(){

	int a[]={1,2,3,2,1};
	int n=sizeof(a)/sizeof(int);

	node *head=createList(a,n);
	
	if(isPalindrome(head)) cout<<"Palindrome!";
	else cout<<"Not Palindrome!";

	return 0;
}