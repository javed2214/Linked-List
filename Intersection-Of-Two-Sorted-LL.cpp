// Program to Find Intersection of Two Sorted Linked List

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

node *findIntersection(node *head1, node *head2){

	if(head1 == NULL or head2 == NULL) return NULL;

	node *p1 = head1, *p2 = head2;

	node *new_head = NULL, *next_node = NULL;

	while(p1 != NULL and p2 != NULL){

		int x1,x2;

		x1 = p1->data;
		x2 = p2->data;

		if(x1 == x2){
			if(new_head == NULL){
				new_head = p1;
				next_node = new_head;
			}
			else{
				next_node->next = p1;
				next_node = next_node->next;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if(x1 > x2){
			p2 = p2->next;
		}
		else p1 = p1->next;
	}

	next_node->next = NULL;

	return new_head;
}

int main(){

	int a[] = {1,4,7,8,9,10};
	int n1 = sizeof(a)/sizeof(int);

	int b[] = {1,2,4,6,7,8};
	int n2 = sizeof(b)/sizeof(int);

	node *head1 = createList(a,n1);
	node *head2 = createList(b,n2);

	printList(head1);
	printList(head2);

	node *head = findIntersection(head1,head2);

	cout<<"\nIntersection: \n";

	printList(head);

	return 0;
}