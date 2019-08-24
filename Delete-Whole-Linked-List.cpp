// Program to Delete Whole Linked List
// https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{

	int data;
	struct node *next;
	
}node;

node *creteList(int *a, int n){

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

void deleteList(node **head){

	node *p = *head, *next = NULL;

	while(p != NULL){

		next = p->next;
		delete(p);
		p = next;
	}

	*head = NULL;
}

void printList(node *head){

	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int main(){

	int a[] = {1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(int);

	node *head = creteList(a,n);
	printList(head);

	deleteList(&head);
	printList(head);

	return 0;
}