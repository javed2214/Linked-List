// Delete N Nodes After M Nodes of a Linked List
// https://www.geeksforgeeks.org/delete-n-nodes-after-m-nodes-of-a-linked-list/

// [1 2 3 4 5 6 7 8] m = 3 and n = 2 ==>> [1 2 3 6 7 8]
// Deleting Two Nodes and Retaining Three Nodes

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

node *deleteNodes(node *head, int m, int n){

	node *p = head;

	while(p){

		for(int i=1;i<m and p != NULL;i++) p = p->next;

		if(p == NULL) return head;

		node *t = p->next;

		for(int i=1;i<=n and t != NULL;i++){

			node *temp = t;
			t = t->next;
			free(temp);
		}	
		p->next = t;
		p = t;
	}
	return head;
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8};
	int siz = sizeof(a) / sizeof(int);

	node *head = createList(a,siz);
	printList(head);

	int m = 3, n = 2;

	head = deleteNodes(head, m, n);
	printList(head);

	return 0;
}