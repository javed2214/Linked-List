// Delete All Occurrences of a Given Key in a Linked List
// 1->2->3->2->2->2->4->2 (Key = 2) --->>> 1->3->4

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;

node *createList(int *a, int n){

	node *head = NULL, *p;

	for(int i=0;i<n;i++){
		node *temp = (node *)malloc(sizeof(node));
		temp->data = a[i];
		temp->next = NULL;

		if(head == NULL) head = temp;
		else{
			p = head;
			while(p->next)
				p=p->next;
			p->next = temp;
		}
	}
	return head;
}

void printList(node *head){

	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}

node *deleteOcc(node *head, int x){

	while(head and head->data == x)		// Removes Head
		head = head->next;

	if(!head) return NULL;

	node *prev, *curr;

	prev = head;
	curr = head->next;

	while(curr){
		
		if(curr->data == x)
			prev->next = curr->next;
		else
			prev = curr;

		curr = curr->next;
	}

	return head;
}

int main(){

	int a[]={1,2,2,2,3,4,5,6,2,7,8};
	int n = sizeof(a)/sizeof(int);

	node *head = createList(a,n);

	printList(head);

	int x;
	cin>>x;

	head = deleteOcc(head,x);
	
	printList(head);

	return 0;
}