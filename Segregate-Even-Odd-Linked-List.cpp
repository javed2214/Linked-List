// Segregate Even Odd Linked List
// https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/

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

node *segregateList(node *head){

	node *p = head;

	node *evenStart = NULL, *evenEnd = NULL;
	node *oddStart = NULL, *oddEnd = NULL;

	while(p){

		int x = p->data;

		if(x % 2 == 0){

			if(evenStart == NULL){
				evenStart = p;
				evenEnd = p;
			}
			else{
				evenEnd->next = p;
				evenEnd = evenEnd->next;
			}
		}
		else{

			if(oddStart == NULL){
				oddStart = p;
				oddEnd = p;
			}
			else{
				oddEnd->next = p;
				oddEnd = oddEnd->next;
			}
		}
		p = p->next;
	}
	evenEnd->next = oddStart;
	oddEnd->next = NULL;

	return head;
}

void printList(node *head){

	while(head){
		cout<<head->data<<"=>";
		head = head->next;
	}
	cout<<endl;
}

int main(){

	int a[] = {4,2,1,8,9,3,2,6,12};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);
	printList(head);

	head = segregateList(head);
	printList(head);

	return 0;
}