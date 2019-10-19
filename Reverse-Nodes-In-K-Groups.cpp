// Reverse Nodes In K Groups - LeetCode
// [1,2,3,4,5] k = 3  -->>  [3,2,1,4,5]

// Similar Question : https://github.com/javed2214/Linked-List/blob/master/Reverse-LL-In-Groups.cpp
// https://leetcode.com/problems/reverse-nodes-in-k-group/

class Solution {
public:

	ListNode *reverse(ListNode *head, ListNode *tail){

		ListNode *p = head, *t1 = tail, *t2 = NULL;

		while(p != tail){

			t2 = p->next;
			p->next = t1;
			t1 = p;
			p = t2;
		}

		return t1;
	}

	ListNode* reverseKGroup(ListNode* head, int k){

		ListNode *p = head;

		for(int i=0;i<k;i++){

			if(p == NULL) return head;
			p = p->next;
		}

		ListNode *new_head = reverse(head, p);
		head->next = reverseKGroup(p, k);

		return new_head;
	}
};