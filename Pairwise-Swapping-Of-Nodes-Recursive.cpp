// Pairwise Swapping of Nodes in a Linked List
// https://leetcode.com/problems/swap-nodes-in-pairs/

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

node *pairwiseSwap(node *head){

	if(head == NULL or head->next == NULL) return head;

	node *remaining = head->next->next;
	
	node *new_head = head->next;
	head->next->next = head;
	
	head->next = pairwiseSwap(remaining);

	return new_head;
}

void printList(node *head){

	while(head){

		cout<<head->data<<"=>";
		head = head->next;
	}
	cout<<endl;
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);
	printList(head);

	head = pairwiseSwap(head);
	printList(head);

	return 0;
}