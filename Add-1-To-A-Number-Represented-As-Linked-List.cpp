// Add 1 to a Number Represented as Linked List
// https://www.geeksforgeeks.org/add-1-number-represented-linked-list/

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

node *reverseList(node *head){

	if(!head or !head->next) return head;
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
	cout<<endl;
}

node *addOne(node *head){

	head = reverseList(head);
	
	node *p = head, *temp = NULL;
	int carry = 1, sum = 0;

	while(p){

		sum = p->data + carry;
		
		if(sum >= 10){
			
			carry = sum / 10;
			sum %= 10;
		}
		else carry = 0;

		p->data = sum;
		temp = p;

		p = p->next;
	}

	if(carry) temp->next = createNode(carry);

	head = reverseList(head);

	return head;
}

int main(){

	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];

	node *head = createList(a,n);
	printList(head);

	node *new_head = addOne(head);
	printList(new_head);

	return 0;
}