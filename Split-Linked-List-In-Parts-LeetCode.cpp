// Split Linked List in K Parts - LeetCode
// https://leetcode.com/problems/split-linked-list-in-parts/

// Input:
// root = [1, 2, 3], k = 5
// Output: [[1],[2],[3],[],[]]

// Input: 
// root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
// Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k){

    	int len = 0;

    	for(ListNode *p = head; p; p = p->next) len++;

    	int n = (len / k), r = (len % k);

    	ListNode *p = head, *prev = NULL;

    	vector <ListNode *> v (k, NULL);

    	for(int i = 0; p and i < k; i++, r--){

    		v[i] = p;

    		for(int j = 0; j < n + (r > 0); j++){

    			prev = p;
    			p = p->next;
    		}
    		prev->next = NULL;
    	}

    	return v;
    }
};