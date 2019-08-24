// Program to Make Middle Node as Head of Linked List

#include<bits/stdc++.h>
using namespace std;

typedef struct node{

	int data;
	struct node *next;
}node;

node *createList(int *a, int n){

	node *head = NULL, *p = NULL;

	for(int i=0;i<n;i++){
		node *temp = (node *)malloc(sizeof(node));
		temp->data = a[i];
		temp->next = NULL;
		if(head == NULL) head = temp;
		else{
			p = head;
			while(p->next) p = p->next;
			p->next = temp;
		}
	}
	return head;
}

void printList(node *head){

	while(head){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

node *makeMiddleHead(node *head){

	node *slow,*fast,*prev;
	slow = fast = head;

	while(slow and fast and fast->next){	// At the End of while() Loop *slow is Middle Element
											// *prev is Previous of *slow
		prev = slow;

		slow = slow->next;
		fast = fast->next->next;
	}

	node *p = prev->next;
	prev->next = p->next;

	node *q = head;
	head = p;
	p->next = q;

	return head;
}

int main(){

	int a[] = {1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(int);

	node *head = createList(a,n);

	printList(head);

	head = makeMiddleHead(head);

	printList(head);

	return 0;
}