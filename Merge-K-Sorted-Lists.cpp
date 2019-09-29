// Program to Merge K Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/


// ***************************** METHOD 1 ************************************
// O(n) Space Complexity

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



// ***************************** METHOD 2 ************************************
// O(1) Space Complexity


class Solution {
public:
    
    ListNode *mergeTwoLists(ListNode *head1, ListNode *head2){
        
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        
        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        }
        else{
            head2->next = mergeTwoLists(head1, head2->next);
            return head2;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
                
        if(lists.size() == 0) return NULL;
        
        while(lists.size() > 1){
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
};
