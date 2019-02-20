// Program to reverse Doubly Linked List

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createList(vector<int> &v){

	node *head=NULL,*temp,*p;
	for(int i=0;i<v.size();i++){
		temp=(node *)malloc(sizeof(node));
		temp->data=v[i];
		temp->left=NULL;
		temp->right=NULL;
		
		if(head==NULL) head=temp;
		else{
			p=head;
			while(p->right!=NULL)
				p=p->right;
			p->right=temp;
			temp->left=p;
		}
	}
	return head;
}

void printList(node *head){

	while(head!=NULL){
		cout<<head->data<<"<=>";
		head=head->right;
	}
	cout<<"\n";
}

node *reverseList(node *head){

	node *temp,*p=head;
	
	if(head==NULL) return NULL;
	if(head->right==NULL) return head;

	while(p!=NULL){
		temp=p->left;		// Node Swapping
		p->left=p->right;
		p->right=temp;
		p=p->left;
	}
	head=temp->left;
	
	return head;
}

int main(){

	std::vector<int> v={1,2,3,4,5,6,7};
	node *head=NULL;
	head=createList(v);
	printList(head);

	cout<<"Reversed DLL: ";
	head=reverseList(head);
	printList(head);

	return 0;
}