// Program to Divide Linked List Into Two Halves

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

void printList(node *head){

	while(head){
		cout<<head->data<<"=>";
		head = head->next;
	}

	cout << endl;
}

void divideList(node *head){

	node *slow = head, *fast = head;
	node *mid = NULL;

	while(fast and fast->next){

		mid = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	node *first = head;
	node *second = slow;

	mid->next = NULL;

	printList(first);
	printList(second);
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);

	printList(head);
	cout<<endl;

	divideList(head);

	return 0;
}