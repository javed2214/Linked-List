// Linked List Components - LeetCode
// https://leetcode.com/problems/linked-list-components/

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G){

    	unordered_set <int> S(G.begin(), G.end());
    	int res = 0;

    	while(head){
    		if(S.count(head->val) and (head->next == NULL or !S.count(head->next->val))) res++;
    		head = head->next;
    	}

    	return res;
    }
};