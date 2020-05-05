// Merge Two Sorted List Iteratively
// https://leetcode.com/problems/merge-two-sorted-lists/
// Time Complexity: O(n + m)  n, m => Length of Linked Lists
// Space Complexity: O(1)


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode fake(-1);
        ListNode *new_head = &fake;
        
        while(l1 != NULL and l2 != NULL){
            if(l1->val <= l2->val){
                new_head->next = l1;
                new_head = l1;
                l1 = l1->next;
            }
            else{
                new_head->next = l2;
                new_head = l2;
                l2 = l2->next;
            }
        }
        if(l1 != NULL) new_head->next = l1;
        if(l2 != NULL) new_head->next = l2;
        
        return fake.next;
    }
};