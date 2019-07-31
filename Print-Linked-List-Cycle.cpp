// Detect and Print Linked List Cycle
// https://www.youtube.com/watch?v=0b4u72Kymqw&list=PLEJXowNB4kPxQIN2dCUAnQ_92HIziG4x6&index=2

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
}node;


node *createNode(int n){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = n;
	temp->next = NULL;

	return temp;
}


node *detectCycle(node *head){

	if(!head) return NULL;

	node *fast, *slow;
	fast = slow = head;

	while(fast and fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast) return slow;
	}
	return NULL;
}


int main(){

	node *head = createNode(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);
	head->next->next->next->next->next = createNode(6);
	head->next->next->next->next->next->next = head->next->next; // (6 -> 3)

	node *x = detectCycle(head);

	if(!x) cout<<"No Cycle!";
	else{
		cout<<"Cycle is Present!\n";
		node *p = head;

		while(p != x){
			p = p->next;
			x = x->next;

			if(p == x){
				cout<<"Junction Node: "<<x->data<<endl;
				break;
			}
		}
		cout<<"\nCycle: \n";
		do{
			cout<<p->data<<"->";
			p=p->next;
		} while(p != x);

	}

	cout<<endl;

	return 0;
}
