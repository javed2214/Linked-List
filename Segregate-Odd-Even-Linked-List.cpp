// Segregate Odd Even Linked List Elements
// https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

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

void printList(node *head){

	while(head){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

void segregate(node **head){

	node *evenStart, *oddStart, *evenEnd, *oddEnd;
	evenStart = oddStart = evenEnd = oddEnd = NULL;

	node *p = *head;

	while(p != NULL){

		int x = p->data;

		if(x % 2 == 0){
			
			if(evenStart == NULL){
				evenStart = p;
				evenEnd = evenStart;
			}
			else{
				evenEnd->next = p;
				evenEnd = evenEnd->next;
			}
		}
		else{
			if(oddStart == NULL){
				oddStart = p;
				oddEnd = oddStart;
			}
			else{
				oddEnd->next = p;
				oddEnd = oddEnd->next;
			}
		}
		p = p->next;
	}

	// If Either of the Two LL is NULL, No Change is Required

	if(oddStart == NULL or oddEnd == NULL) return;

	evenEnd->next = oddStart;
	oddEnd->next = NULL;

	printList(evenStart);
}

int main(){

	int a[] = {1,2,3,4,5,6,7,10};
	int n = sizeof(a)/sizeof(int);

	node *head = creteList(a,n);
	printList(head);

	segregate(&head);

	return 0;
}