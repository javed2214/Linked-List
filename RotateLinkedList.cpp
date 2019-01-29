// https://leetcode.com/problems/rotate-list/
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL) return NULL;
        ListNode *p=head;
        int a[1000],b[1000],i=0;
        while(p){
            a[i++]=p->val;
            p=p->next;
        }
        for(int j=0;j<i;j++){
            b[(j+k)%i]=a[j];
        }
        p=head;i=0;
        while(p){
            p->val=b[i++];
            p=p->next;
        }
        return head;
    }
};