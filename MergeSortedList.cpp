// Program to Merge Two Sorted List
// [1,3,5] + [2,4,6] ==>> [1,2,3,4,5,6]

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *createNode(int *a, int n){
	node *temp,*head=NULL,*p;
	for(int i=0;i<n;i++){
		temp=(node *)malloc(sizeof(node));
		temp->data=a[i];
		temp->next=NULL;
		if(head==NULL)
			head=temp;
		else{
			p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=temp;
		}
	}
	return head;
}
void traverseList(node *head){
	node *p;
	if(head==NULL)
		printf("List is Empty!");
	else{
		p=head;
		while(p!=NULL){
			printf("[%d]=>",p->data);
			p=p->next;
		}
	}
}
node *mergeList(node *head1, node *head2){

	node *p,*q;
	int a[100],i=0;
	p=head1;q=head2;
	while(p and q){
		if(p->data<q->data){
			a[i++]=p->data;
			p=p->next;
		}
		else{
			a[i++]=q->data;
			q=q->next;
		}
	}
	while(p){
		a[i++]=p->data;
		p=p->next;
	}
	while(q){
		a[i++]=q->data;
		q=q->next;
	}
	head1=createNode(a,i);

	return head1;
}
int main(){

	node *head1=NULL,*head2=NULL,*head=NULL;
	int a[]={1,3,5};
	int b[]={2,4,6};
	int n=sizeof(a)/sizeof(int);
	head1=createNode(a,n);
	head2=createNode(b,n);
	traverseList(head1);
	cout<<"\n";
	traverseList(head2);
	head=mergeList(head1,head2);
	cout<<"\n";
	traverseList(head);

	return 0;
}
