// Program to Remove nth Node from Linked List

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *createNode(int *a, int n){

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

void printList(node *head){

	while(head){
		cout<<head->data<<"=>";
		head=head->next;
	}
	cout<<"\n";
}

node *removeNode(node *head, int n, int total){

	node *p=head;

	if(n==1){
		head=p->next;
		free(p);
	}
	else if(n==total){
		for(int i=1;i<total-1;i++)
			p=p->next;
		p->next=NULL;
	}
	else if(n>1 and n<total){
		for(int i=1;i<n-1;i++)
			p=p->next;
		node *temp=p->next;
		p->next=temp->next;
		free(temp);
	}
	else cout<<"Invalid Node!\n";

	return head;
}

int main(){

	int a[]={1,2,3,4,5,6,7,8};
	int n=sizeof(a)/sizeof(int);

	node *head=createNode(a,n);
	printList(head);

	int k;
	cout<<"Enter nth Node: ";
	cin>>k;
	head=removeNode(head,k,n);
	printList(head);

	return 0;
}