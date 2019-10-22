// Delete Alternate Nodes of Liked List
// 1->2->3->4->5->6  ==>>  1->3->5
// https://www.geeksforgeeks.org/delete-alternate-nodes-of-a-linked-list/

node *deleteAlternateNodes(node *head){

	node *p, *q;

	p = head;
	q = head->next;

	while(p != NULL and q != NULL){

		p->next = q->next;
		delete(q);
		p = p->next;
		if(p != NULL) q = p->next;
	}

	return head;
}