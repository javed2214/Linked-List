// Program to Find Union and Intersection of Linked List

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

void printList(node *head){

	while(head!=NULL){
		cout<<head->data<<"=>";
		head=head->next;
	}
	cout<<"\n";
}

node *findUnion(node *head1, node *head2){

	unordered_map <int,int> Map;
	node *p1=head1, *p2=head2;

	while(p1){
		Map[p1->data]++;
		p1=p1->next;
	}
	while(p2){
		Map[p2->data]++;
		p2=p2->next;
	}
	node *head=NULL, *p;
	for(auto it:Map){
		node *temp=(node *)malloc(sizeof(node));
		temp->data=it.first;
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

node *findIntersection(node *head1, node *head2){

	unordered_map <int,int> Map;
	node *p1=head1, *p2=head2;

	while(p1){
		if(Map.find(p1->data)==Map.end())
			Map[p1->data]++;
		p1=p1->next;
	}
	while(p2){
		Map[p2->data]++;
		p2=p2->next;
	}
	node *head=NULL, *p;
	for(auto it:Map){
		if(it.second>=2){
			node *temp=(node *)malloc(sizeof(node));
			temp->data=it.first;
			temp->next=NULL;
			if(head==NULL) head=temp;
			else{
				p=head;
				while(p->next!=NULL)
					p=p->next;
				p->next=temp;
			}
		}
	}
	return head;
}

int main(){

	int a[]={10,15,4,20};
	int n1=sizeof(a)/sizeof(int);

	int b[]={8,4,2,10};
	int n2=sizeof(b)/sizeof(int);

	node *head1=NULL, *head2=NULL;
	head1=createList(a,n1);
	head2=createList(b,n2);

	printList(head1);
	printList(head2);

	node *un=findUnion(head1,head2);

	cout<<"Union: ";
	printList(un);

	node *in=findIntersection(head1,head2);

	cout<<"Intersection: ";
	printList(in);

	return 0;
}