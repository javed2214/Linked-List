// Reorder Linked List - LeetCode
// 1->2->3->4->5->6->7->8  ==>>  1->8->2->7->3->6->4->5
// https://leetcode.com/problems/reorder-list/

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

node *reverseList(node *head){

	node *p = head, *t1 = NULL, *t2 = NULL;

	while(p){

		t2 = p->next;
		p->next = t1;
		t1 = p;
		p = t2;
	}

	return t1;
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);
	printList(head);

	node *slow, *fast, *prev;

	slow = head;
	fast = head;

	while(fast and fast->next){
		
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	prev->next = NULL;
	slow = reverseList(slow);

	node *p = head, *q = slow;

	while(q != NULL){

		node *next = p->next;
		p->next = q;
		p = q;
		q = next;
	}

	printList(head);

	return 0;
}