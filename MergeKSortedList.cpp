// https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
                
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
        
        for(int i=0;i<lists.size();i++){
            ListNode *head = lists[i];
            while(head != NULL){
                pq.push({head->val, head});
                head = head->next;
            }
        }
      
        ListNode *head = NULL, *p = NULL;
        
        while(!pq.empty()){
            ListNode *temp = pq.top().second;
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
