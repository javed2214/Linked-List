// Program to Add Two Numbers Represented In the Form of Linked List

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *createList(std::vector<int> &a){

	node *head=NULL,*temp=NULL;
	for(int i=0;i<a.size();i++){
		temp=(node *)malloc(sizeof(node));
		temp->data=a[i];
		temp->next=NULL;

		if(head==NULL) head=temp;
		else{
			node *p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=temp;
		}
	}
	return head;
}

void displayList(node *head){

	node *p=head;
	while(p!=NULL){
		cout<<p->data<<"=>";
		p=p->next;
	}
	cout<<"\n";
}

node *reverseList(node *head){

	node *t1=NULL,*t2=NULL,*p=head;
	if(head==NULL) return NULL;
	else{
		while(p!=NULL){
			t2=p->next;
			p->next=t1;
			t1=p;
			p=t2;
		}
	}
	return t1;
}

vector<int> addList(node *head1, node *head2){

	int sum=0,carry=0;
	std::vector<int> v;
	while(head1!=NULL or head2!=NULL){

		if(head1!=NULL){
			sum+=head1->data;
			head1=head1->next;
		}
		if(head2!=NULL){
			sum+=head2->data;
			head2=head2->next;
		}
		sum+=carry;
		v.push_back(sum%10);
		carry=sum/10;
		sum=0;
	}
	if(carry) v.push_back(carry);

	return v;
}

int main(){

	std::vector<int> a,b;
	a={9,9,2,3,5,9,7,6,8};
	b={9,9,6,7,8,4,6};

	node *head1,*head2;
	head1=createList(a);
	head2=createList(b);

	head1=reverseList(head1);
	head2=reverseList(head2);

	displayList(head1);
	displayList(head2);

	std::vector<int> v;
	v=addList(head1,head2);
	
	node *res=createList(v);
	res=reverseList(res);

	cout<<"Result: ";
	displayList(res);


	return 0;
}
