// Implementation of XOR Linked List
// https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-2/

#include<bits/stdc++.h>
using namespace std;

struct node{

	int data;
	struct node *npx;

};

node *XOR(node *a, node *b){

	return (node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insertNode(node **head_ref, int x){

	node *temp = new node();
	temp->data = x;

	temp->npx = XOR(*head_ref, NULL);

	if(*head_ref != NULL){

		node *next = XOR((*head_ref)->npx, NULL);
		(*head_ref)->npx = XOR(temp, next);
	}

	*head_ref = temp;
}

void printList(node *head){

	node *curr = head;
	node *prev = NULL;
	node *next;

	while(curr != NULL){

		cout<<curr->data<<" ";
		next = XOR(prev, curr->npx);
		prev = curr;
		curr = next;
	}
}

int main(){

	node *head = NULL;
	
	insertNode(&head, 10);
	insertNode(&head, 20);
	insertNode(&head, 30);
	insertNode(&head, 40);

	printList(head);
}