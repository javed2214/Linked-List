// Reverse Linked List in Groups of Given Size
// Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
// Output:  3->2->1->6->5->4->8->7->NULL

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *reverseInGroups(node *head, int k){

	node *p=head,*t1=NULL,*t2=NULL;
	int count=0;

	while(p!=NULL and count<k){
		t2=p->next;
		p->next=t1;
		t1=p;
		p=t2;
		count++;
	}
	if(t2!=NULL)
		head->next=reverseInGroups(t2,k);

	return t1;
}

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

int main(){

	int a[]={1,2,3,4,5,6,7,8};
	int n=sizeof(a)/sizeof(int);

	int k=3;
	node *head=createList(a,n);
	head=reverseInGroups(head,k);

	while(head){
		cout<<head->data<<"->";
		head=head->next;
	}
	return 0;	
}