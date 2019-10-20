// Delete Nth Node from End of the Linked List
// https://www.geeksforgeeks.org/delete-nth-node-from-the-end-of-the-given-linked-list/

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

		if(head == NULL) head = temp, p = head;
		else p->next = temp, p = p->next;
	}

	return head;
}

void printList(node *head){

	while(head){
		cout<<head->data<<"=>";
		head = head->next;
	}
}

int main(){

	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a) / sizeof(int);

	node *head = createList(a,n);

	int k; cin>>k;

	if(k == n){
		
		node *p = head;
		head = head->next;
		delete(p);
		
		printList(head);
		
		return 0;
	}

	node *p = head, *q = head, *prev = NULL;

	for(int i=0;i<k;i++) p = p->next;

	while(p){
		
		p = p->next;
		prev = q;
		q = q->next;
	}
	
	prev->next = q->next;

	delete q;

	printList(head);

	return 0;
}


// ***************************** METHOD 2 ***********************************
// EFFICIENT ONE


class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL) return NULL;
        
        ListNode *p = head, *q = head;
        
        while(n--) p = p->next;
        
        if(!p) return head->next;
                
        while(p->next){
            
            p = p->next;
            q = q->next;
        }
        
        q->next = q->next->next;
        
        return head;
    }
};