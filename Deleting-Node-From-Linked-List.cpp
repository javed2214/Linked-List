#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *createList(int *a, int n){

	node *head=NULL, *p;

	for(int i=0;i<n;i++){
		node *temp = (node *)malloc(sizeof(node));
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

	while(head){
		cout<<head->data<<"=>";
		head=head->next;
	}
	cout<<"\n";
}

node *deleteNode(node *head, int d){

	if(head == NULL) return NULL;
	if(head->data == d) return head->next;

	node *p=head;

	while(p->next){
		if(p->next->data == d){
			p->next = p->next->next;
			return head;
		}
		p=p->next;
	}
	return head;
}

int main(){

	int a[]={1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(int);

	node *head = createList(a,n);
	printList(head);

	int d;
	cin>>d;
	head = deleteNode(head,d);

	printList(head);


	delete head;

	return 0;
}