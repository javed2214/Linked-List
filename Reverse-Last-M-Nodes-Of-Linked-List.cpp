// Reverse Last m Nodes of Linked List using Recursion
// [1 2 3 4 5 6 7] m = 3  =>>  [1 2 3 4 7 6 5]

#include<bits/stdc++.h>
using namespace std;

struct node{

	int data;
	struct node *next;

};

node *createList(int *a, int n){

	node *head = NULL, *p = NULL;

	for(int i=0;i<n;i++){

		node *temp = (node *)malloc(sizeof(node));
		temp->data = a[i];
		temp->next = NULL;

		if(head == NULL){

			head = temp;
			p = head;
		}
		else{

			p->next = temp;
			p = p->next;
		}
	}
	return head;
}

node *succ = NULL;

node *reverseList(node *head, int m){

	if(m == 1){

		succ = head->next;
		return head;
	}

	node *new_head = reverseList(head->next, m - 1);
	head->next->next = head;
	head->next = succ;

	return new_head;
}

void printList(node *head){

	while(head){

		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

int Length(node *head){

	if(head == NULL) return 0;
	return 1 + Length(head->next);
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);
	
	int len = Length(head);
	int m = 4;

	int k = len - m;

	node *p = head;

	for(int i=0;i<k-1;i++) p = p->next;

	p->next = reverseList(p->next, m);

	printList(head);

	return 0;
}