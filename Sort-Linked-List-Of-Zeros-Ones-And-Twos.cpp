// Sort Linked List of 0's, 1's and 2's
// https://www.geeksforgeeks.org/sort-linked-list-0s-1s-2s-changing-links/

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

node *createNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;

	return temp;
}

node *sortList(node *head){

	node *zeroD = createNode(0);
	node *oneD = createNode(0);
	node *twoD = createNode(0);

	node *zero = zeroD, *one = oneD, *two = twoD;

	node *p = head;

	while(p){

		if(p->data == 0){
			zero->next = p;
			zero = zero->next;
		}
		else if(p->data == 1){
			one->next = p;
			one = one->next;
		}
		else if(p->data == 2){
			two->next = p;
			two = two->next;
		}
		p = p->next;
	}

	zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
	one->next = twoD->next;
	two->next = NULL;

	head = zeroD->next;

	delete(zeroD);
	delete(oneD);
	delete(twoD);

	return head;
}

void printList(node *head){

	while(head){

		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

int main(){

	int a[] = {1,0,2,2,1,0,1,0,2};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);
	printList(head);

	head = sortList(head);
	printList(head);

	return 0;
}