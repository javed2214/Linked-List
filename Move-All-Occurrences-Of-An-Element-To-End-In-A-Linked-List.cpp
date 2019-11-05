// Move All Occurrence of Element to the End of the Linked List
// https://www.geeksforgeeks.org/move-occurrences-element-end-linked-list/

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

void moveElement(node *head, int k){

	node *pKey = head;
	node *pCrawl = head;

	while(pCrawl != NULL){

		if(pCrawl != pKey and pCrawl->data != k){

			swap(pKey->data, pCrawl->data);
			pKey = pKey->next;
		}
		
		if(pKey->data != k) pKey = pKey->next;

		pCrawl = pCrawl->next;
	}
}

void printList(node *head){

	while(head){

		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

int main(){

	int a[] = {1,2,3,4,3,6,8,3};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);
	printList(head);

	int k = 3;

	moveElement(head, k);
	printList(head);

	return 0;
}