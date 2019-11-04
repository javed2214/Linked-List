// Flattening a Linked List
// https://www.geeksforgeeks.org/flattening-a-linked-list/

node *mergeList(node *head1, node *head2){

	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	if(head1->data <= head2->data){
		head1->next = mergeList(head1->down, head2);
		return head1;
	}

	else{
		head2->next = mergeList(head1, head2->down);
		return head2;
	}
}

node *flatten(node *head){

	if(head == NULL or head->right == NULL) return head;

	return mergeList(head, flatten(head->right));
}