// Proogram to Delete Middle Element of Linked List
// https://www.geeksforgeeks.org/delete-middle-of-linked-list/

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
			while(p->next != NULL) p = p->next;
			p->next = temp;
		}
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

node *deleteMiddle(node *head){

	if(head == NULL or head->next == NULL) return NULL;

	node *slow = head, *fast = head, *mid = NULL;

	while(fast and fast->next){
		
		mid = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	
	mid->next = slow->next;

	delete slow;

	return head;
}

int main(){

	int a[] = {1,2,3,4,5};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);

	printList(head);

	head = deleteMiddle(head);

	printList(head);

	return 0;
}