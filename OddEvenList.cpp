// https://leetcode.com/problems/odd-even-linked-list/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL) return head;
        ListNode *p,*q,*r=head->next;
        p=head;q=head->next;
        while( q!=NULL and q->next!=NULL){
            p->next=p->next->next;
            q->next=q->next->next;
            p=p->next;
            q=q->next;
        }
        p->next=r;
        
        return head;
    }
};