// Find Triplet from Three Linked Lists With Sum Equal to a Given Number
// https://www.geeksforgeeks.org/find-a-triplet-from-three-linked-lists-with-sum-equal-to-a-given-number/

// Naive Approach - Three Nested Loops [O(n^3)] Complexity

// Efficient Algorithm :-
// Sort List B in Ascending Order and C in Descending Order
// Now Pick Element One by One and find Pair by Traversing both B and C

// Overall TC : [O(n^2)]
// Merge Sort TC : [O(nlog(n))]

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

void frontBackSplit(node *head, node **front, node **back){

	node *slow = head, *fast = head;
	node *mid = NULL;

	while(fast and fast->next){

		mid = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	*front = head;
	*back = slow;
	mid->next = NULL;
}

node *sortedMergeAsc(node *head1, node *head2){

	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	if(head1->data <= head2->data){
		head1->next = sortedMergeAsc(head1->next, head2);
		return head1;
	}
	else{
		head2->next = sortedMergeAsc(head1, head2->next);
		return head2;
	}
}

node *sortedMergeDes(node *head1, node *head2){

	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	if(head1->data >= head2->data){
		head1->next = sortedMergeDes(head1->next, head2);
		return head1;
	}
	else{
		head2->next = sortedMergeDes(head1, head2->next);
		return head2;
	}
}

void sortListAscending(node **headRef){

	node *head = *headRef;
	node *a, *b;

	if(head == NULL or head->next == NULL) return;

	frontBackSplit(head, &a, &b);

	sortListAscending(&a);
	sortListAscending(&b);

	*headRef = sortedMergeAsc(a,b);
}

void sortListDescending(node **headRef){

	node *head = *headRef;
	node *a, *b;

	if(head == NULL or head->next == NULL) return;

	frontBackSplit(head, &a, &b);

	sortListDescending(&a);
	sortListDescending(&b);

	*headRef = sortedMergeDes(a,b);
}

int main(){

	int a[] = {12,6,29};
	int n1 = sizeof(a) / sizeof(int);

	int b[] = {23,5,8};
	int n2 = sizeof(b) / sizeof(int);

	int c[] = {90,20,59};
	int n3 = sizeof(c) / sizeof(int);

	int k = 101;

	node *head1 = createList(a,n1);
	node *head2 = createList(b,n2);
	node *head3 = createList(c,n3);

	sortListAscending(&head2);
	sortListDescending(&head3);

	while(head1){

		node *b = head2;
		node *c = head3;

		while(b and c){

			int x = head1->data + b->data + c->data;

			if(x == k){
				cout<<head1->data<<" "<<b->data<<" "<<c->data<<endl;
				cout<<"Yes";
				return 0;
			}
			else if(x < k) b = b->next;

			else c = c->next;
		}

		head1 = head1->next;
	}

	cout<<"No";

	return 0;
}