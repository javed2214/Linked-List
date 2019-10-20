// Program to Reverse First N Elements of Linked List

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
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

node *succ = NULL;

node *reverseKNodes(node *head, int k){

	if(k == 1){

		succ = head->next;
		return head;
	}

	node *p = reverseKNodes(head->next, k - 1);
	head->next->next = head;
	head->next = succ;

	return p;
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);
	printList(head);

	int k; cin>>k;

	head = reverseKNodes(head, k);

	printList(head);

	return 0;
}