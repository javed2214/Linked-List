// https://leetcode.com/problems/merge-k-sorted-lists/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>&v) {
        
        typedef pair<int,ListNode*>pi;
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        for(int i=0;i<v.size();i++){
            ListNode *p=v[i];
            while(p!=NULL){
                pq.push(make_pair(p->val,p));
                p=p->next;
            }
        }
        ListNode* head=NULL;
        ListNode *temp;
        while(!pq.empty()){
            temp=(ListNode *)malloc(sizeof(ListNode));
            temp->val=pq.top().first;
            temp=pq.top().second;
            temp->next=NULL;
            if(head==NULL)
                head=temp;
            else{
                ListNode *p=head;
                while(p->next!=NULL)
                    p=p->next;
                p->next=temp;
            }
            pq.pop();
        }
        return head;
    }
};