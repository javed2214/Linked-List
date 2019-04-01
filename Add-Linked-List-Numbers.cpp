// Program to Add Numbers Represented in the Form of Linked List
// Output Should be in the Form of Linked List

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

void printList(node *head){

	while(head){
		cout<<head->data<<"=>";
		head=head->next;
	}
	cout<<"\n";
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

node *createNode(int n){

	node *head=new node;
	head->data=n;
	head->next=NULL;

	return head;
}

node *addList(node *head1, node *head2){

	node *head=NULL,*p,*temp;
	int carry=0,x,sum;
	while(head1 and head2){
		
		sum=head1->data+head2->data+carry;
		
		if(sum>=10) x=sum%10, carry=sum/10;
		else x=sum, carry=0;
		
		temp=createNode(x);
		
		if(head==NULL) head=temp,p=head;
		
		else{
			p->next=temp;
			p=p->next;
		}
		
		head1=head1->next;
		head2=head2->next;
	}

	while(head1){
		sum=head1->data+carry;
		if(sum>=10) x=sum%10, carry=sum/10;
		else x=sum, carry=0;

		p->next=createNode(x);
		p=p->next;
		head1=head1->next;
	}
	while(head2){
		sum=head2->data+carry;
		if(sum>=10) x=sum%10, carry=sum/10;
		else x=sum, carry=0;

		p->next=createNode(x);
		p=p->next;
		head2=head2->next;
	}
	if(carry) p->next=createNode(carry);

	return head;
}

int main(){

	int a[]={9,8,2,7,3};
	int n1=sizeof(a)/sizeof(int);

	int b[]={2,9,5,2};
	int n2=sizeof(b)/sizeof(int);

	node *head1=createList(a,n1);
	printList(head1);

	node *head2=createList(b,n2);
	printList(head2);

	head1=reverseList(head1);
	head2=reverseList(head2);

	node *head=addList(head1,head2);
	head=reverseList(head);

	cout<<"Sum: ";
	printList(head);

	return 0;
}
