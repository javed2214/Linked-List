// Compare Two Strings Represented as Linked List
// https://www.geeksforgeeks.org/compare-two-strings-represented-as-linked-lists/

// Return 0 if both Strings are same
// Return 1 if first is Lexicographically Greater
// Return -1 if second is Lexicographically Greater

int Compare(node *head1, node *head2){

	while(head1 and head2 and head1->data == head2->data){

		head1 = head1->next;
		head2 = head2->next;
	}

	if(head1 and head2) return (head1->data > head2->data) ? 1 : -1;

	if(head1 and !head2) return 1;
	if(head2 and !head1) return -1;

	return 0;
}