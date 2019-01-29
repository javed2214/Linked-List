// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Program to Find Intersection of Two Linked Lists

class Solution {
public:
    
    int getLength(ListNode *head){
        
        if(head==NULL)
            return 0;
        return 1+getLength(head->next);
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *p,*q;
        p=headA;q=headB;
        int l1=getLength(headA);
        int l2=getLength(headB);
        int l=l2>l1?l2-l1:l1-l2;
        if(l1>l2){
            for(int i=0;i<l;i++)
                p=p->next;
        }
        else{
            for(int i=0;i<l;i++)
                q=q->next;
        }
        while(p and q){
            if(p==q)
                return p;
            p=p->next;
            q=q->next;
        }
        return NULL;
    }
};