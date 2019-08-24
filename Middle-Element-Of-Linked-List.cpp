// Program to Find Middle Element of Linked List
// https://www.youtube.com/watch?v=2C7WrpgnLDw&list=PLEJXowNB4kPxQIN2dCUAnQ_92HIziG4x6
// In One Pass

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
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

int findMiddle(node *head){

	node *slow, *fast;
	slow = fast = head;

	while(slow and fast and fast->next){
		
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}

int main(){

	int a[] = {1,2,3,4,5,6,7};
	int n = sizeof(a)/sizeof(int);

	node *head = createList(a,n);
	printList(head);

	cout<<findMiddle(head);

	return 0;
}