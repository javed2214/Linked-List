// Split Linked List Into Two Lists Where Each List Containing Alternating Elements
// https://www.techiedelight.com/split-linked-list-into-two-lists-list-containing-alternating-elements/

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

		if(head == NULL) head = temp, p = head;
		else p->next = temp, p = p->next;
	}

	return head;
}

void printList(node *head){

	while(head){
		cout<<head->data<<"=>";
		head = head->next;
	}
	cout<<endl;
}

void AlternatingSplit(node *a, node *b){

	if(a == NULL or b == NULL) return;
	
	if(a->next) a->next = a->next->next;
	if(b->next) b->next = b->next->next;
	
	AlternatingSplit(a->next, b->next);
}

void helper(node *head, node **aRef, node **bRef){

	*aRef = head;
	*bRef = head->next;

	AlternatingSplit(*aRef, *bRef);
}

int main(){

	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr) / sizeof(int);

	node *head = createList(arr,n);

	printList(head);
	cout<<endl;

	node *a = NULL, *b = NULL;

	helper(head, &a, &b);

	printList(a);
	printList(b);

	return 0;
}