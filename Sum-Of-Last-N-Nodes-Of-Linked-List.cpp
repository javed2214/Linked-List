// Program to Find Sum of Last Nodes of Linked List
// https://www.geeksforgeeks.org/find-sum-last-n-nodes-given-linked-list/

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

//  -------------------- METHOD 1  --------------------

int findSum1(node *head, int n){

	node *p = head, *q = head;
	int sum = 0, temp = 0;

	while(p and n--){

		sum += p->data;
		p = p->next;
	}

	while(p){

		sum += p->data;
		temp += q->data;

		p = p->next;
		q = q->next;
	}

	return (sum - temp);
}

//  -------------------- METHOD 2  --------------------

int findSum2(node *head, int n){

	int len = 0;
	for(node *p = head; p; p = p->next) len++;

	int x = (len - n);
	node *p = head;

	while(p and x--) p = p->next;

	int sum = 0;

	while(p){

		sum += p->data;
		p = p->next;
	}

	return sum;
}

//  -------------------- METHOD 3  --------------------

void findSum3(node *head, int *n, int *sum){

	if(head == NULL) return;

	findSum3(head->next, n, sum);

	if(*n > 0){

		*sum = *sum + head->data;
		--*n;
	}
}

int main(){

	int a[] = {4,1,2,6,8,4,7,9};
	int s = sizeof(a) / sizeof(int);

	node *head = createList(a,s);

	int n;
	cin>>n;

	int sum = 0;

	cout << findSum1(head,n) << endl;
	cout << findSum2(head,n) << endl;
	findSum3(head, &n, &sum);
	cout << sum << endl;

	return 0;
}