// Reverse Linked List II - LeetCode
// https://leetcode.com/problems/reverse-linked-list-ii/


class Solution {
public:
    
    ListNode *succ;
    
    ListNode *reverseList(ListNode *head, int n){
        
        if(n == 1){
           
            succ = head->next;
            return head;
        }

        ListNode *p = reverseList(head->next, n - 1);
        head->next->next = head;
        head->next = succ;
        
        return p;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if(m <= 1) return reverseList(head, n - m + 1);
        
        head->next = reverseBetween(head->next, m - 1, n - 1);
        
        return head;
    }
};