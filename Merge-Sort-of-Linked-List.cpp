// Merge Sort of Linked List
// https://www.geeksforgeeks.org/merge-sort-for-linked-list/

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

void FrontBackSplit(node *head, node **front, node **back){

	node *slow = head, *fast = head;
	node *mid = NULL;

	while(fast != NULL and fast->next){

		mid = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	*front = head;
	*back = slow;
	mid->next = NULL;
}

node *SortedMerge(node *head1, node *head2){

	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;
	
	if(head1->data <= head2->data){
		head1->next = SortedMerge(head1->next, head2);
		return head1;
	}

	else{
		head2->next = SortedMerge(head1, head2->next);
		return head2;
	}
}

void printList(node *head){

	while(head){
		cout<<head->data<<"=>";
		head = head->next;
	}
	cout<<endl;
}

void MergeSort(node **headRef){

	node *head = *headRef;
	node *a, *b;

	if(head == NULL or head->next == NULL) return;

	FrontBackSplit(head, &a, &b);

	MergeSort(&a);
	MergeSort(&b);

	*headRef = SortedMerge(a,b);
}

int main(){

	int a[] = {4,1,6,3,9,8,5};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);

	printList(head);

	MergeSort(&head);

	printList(head);

	return 0;
}