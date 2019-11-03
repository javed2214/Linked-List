// Rearrange a Linked List in Zig Zag Fashion
// https://www.geeksforgeeks.org/linked-list-in-zig-zag-fashion/

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

void zigZag(node *head){

	bool flag = true;

	node *p = head;

	while(p->next != NULL){

		if(flag){

			if(p->data > p->next->data)
				swap(p->data, p->next->data);
		}
		else{

			if(p->data < p->next->data)
				swap(p->data, p->next->data);
		}

		p = p->next;
		flag = !flag;
	}
}

void printList(node *head){

	while(head){

		cout<<head->data<<"->";
		head = head->next;
	}
	cout<<endl;
}

int main(){

	int a[] = {4,1,2,8,5,9,3};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);
	printList(head);

	zigZag(head);
	printList(head);

	return 0;
}