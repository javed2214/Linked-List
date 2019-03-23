// Program to Reverse Doubly Linked List using Recursion

node *reverseDLL(node *head){

	if(head==NULL) return NULL;

	node *temp=head->right;
	head->right=head->left;
	head->left=temp;

	if(head->left==NULL) return head;

	return reverseDLL(head->left);
}