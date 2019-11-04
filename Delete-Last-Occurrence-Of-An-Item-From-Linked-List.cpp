// Delete Last Occurrence of an Element from Linked List
// https://www.geeksforgeeks.org/delete-last-occurrence-of-an-item-from-linked-list/

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

void deleteLastOccurr(node **head, int x){

	node **temp = NULL;

	while(*head){

		if((*head)->data == x)
			temp = head;

		head = &(*head)->next;
	}

	if(temp){

		node *t = *temp;
		*temp = t->next;
		free(t);
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

	int a[] = {3,1,4,6,7,4,5,4,9};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);
	printList(head);

	deleteLastOccurr(&head, 4);
	printList(head);

	return 0;
}