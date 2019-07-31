// Program to Find Middle Element of Linked List
// https://www.youtube.com/watch?v=2C7WrpgnLDw&list=PLEJXowNB4kPxQIN2dCUAnQ_92HIziG4x6

node *findMiddle(node *head){

	if(!head) return NULL;

	node *p,*q;
	p = q = head;

	// p -> Slow Pointer
	// q -> Fast Pointer

	while(q and q->next){
		p = p->next;
		q = q->next;
		if(q) q = q->next;
	}
	return p;
}