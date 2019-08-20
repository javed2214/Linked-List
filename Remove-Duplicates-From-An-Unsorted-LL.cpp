// Program to Remove Duplicates from an Unsorted Linked List

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

int Map[101];

node *create(int *a, int n){

	node *head = NULL, *p = NULL;

	for(int i=0;i<n;i++){
		node *temp = new node();
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

void print(node *head){

	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void removeDuplicates(node *head){

	node *p = head, *q = head->next;
	
	Map[p->data] = 1;

	while(q){

		if(Map[q->data]){

			node *temp = q;
			p->next = q->next;
			q = p->next;
			delete temp;
		}
		else{
			Map[q->data] = 1;
			p = q;
			q = q->next;
		}
	}
}

int main(){

	int a[] = {3,2,4,5,6,2,1,4,6,7,4,4,3,2,5,6,8};
	int n = sizeof(a)/sizeof(int);

	node *head = create(a,n);
	print(head);
	removeDuplicates(head);
	print(head);

	return 0;
}