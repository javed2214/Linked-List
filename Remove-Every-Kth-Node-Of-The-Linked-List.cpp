// Remove Every Kth Node of the Linked List
// https://www.geeksforgeeks.org/remove-every-k-th-node-linked-list/

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

void printList(node *head){

	while(head){
		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

void deleteList(node *head){

	while(head != NULL){

		node *p = head->next;
		delete(head);
		head = p;
	} 
}

node *removeKthNode(node *head, int k){

	if(k == 1){
		deleteList(head);
		return NULL;
	}

	node *p = head;
	int cnt = 1;

	while(p){

		if(cnt == k-1){
			node *q = p->next;
			if(p->next) p->next = p->next->next;
			cnt = 0;
		}
		p = p->next;
		cnt++;
	}
	return head;
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);
	printList(head);

	int k; cin>>k;

	head = removeKthNode(head, k);
	printList(head);

	return 0;
}