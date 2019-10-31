// Add Two Numbers Represented by Linked List
// https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
// [9->2] + [8->1->9] = [9->1->1]

#include<bits/stdc++.h>
using namespace std;

typedef struct node{

	int data;
	struct node *next;

}node;

node *createNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;

	return temp;
}

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

node *addList(node *head1, node *head2){

	node *head = NULL, *p = NULL;
	int carry = 0, sum = 0;

	while(head1 or head2){

		sum = carry;

		if(head1) sum += head1->data;
		if(head2) sum += head2->data;
		
		if(sum >= 10){
			carry = 1;
			sum = sum % 10;
		}
		else carry = 0;
		
		if(head == NULL){
			head = createNode(sum);
			p = head;
		}
		else{
			p->next = createNode(sum);
			p = p->next;
		}

		if(head1) head1 = head1->next;
		if(head2) head2 = head2->next;
	}

	if(carry > 0) p->next = createNode(carry);

	return head;
}

node *reverseList(node *head){

	if(head == NULL or head->next == NULL) return head;

	node *remaining = reverseList(head->next);
	node *new_head = remaining;
	head->next->next = head;
	head->next = NULL;

	return new_head;
}

void printList(node *head){

	while(head){

		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<"\n";
}

int main(){

	int a[] = {9,2};
	int n1 = sizeof(a) / sizeof(int);

	int b[] = {8,1,9};
	int n2 = sizeof(b) / sizeof(int);

	node *head1 = createList(a,n1);
	node *head2 = createList(b,n2);

	printList(head1);
	printList(head2);

	head1 = reverseList(head1);
	head2 = reverseList(head2);

	node *head = addList(head1, head2);
	head = reverseList(head);

	printList(head);

	return 0;
}
