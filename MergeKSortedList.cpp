// https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
                
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0;i<lists.size();i++){
            ListNode *head = lists[i];
            while(head != NULL){
                pq.push(head->val);
                head = head->next;
            }
        }
        ListNode *head = NULL, *p = NULL;
        while(!pq.empty()){
            ListNode *temp = new ListNode(pq.top());
            if(head == NULL) head = temp, p = temp;
            else{
                p->next = temp;
                p = p->next;
            }
            pq.pop();
        }       
        return head;
    }
};
