// Clone Linked List With Random Pointer
// https://www.youtube.com/watch?v=OvpKeraoxW0
// https://leetcode.com/problems/copy-list-with-random-pointer/

// https://github.com/bephrem1/backtobackswe/blob/master/Linked%20Lists/CloneLinkedListWithRandomPointers/CloneLinkedListWithRandomPointers.java

// TC : O(n)
// SC : O(n)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL) return head;
        
        unordered_map <Node *, Node *> Map;
        
        Node *p = head;
        
        while(p != NULL){
            Node *x = new Node(p->val, NULL, NULL);
            Map[p] = x;
            p = p->next;
        }
        
        p = head;
        
        while(p != NULL){
            Map[p]->next = Map[p->next];
            Map[p]->random = Map[p->random];
            p = p->next;
        }
        
        return Map[head];
    }
};


// TC : O(n)
// SC : O(1)


class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL) return head;
        
        Node *p = head, *next = NULL;
        
        while(p != NULL){
            
            next = p->next;
            Node *x = new Node(p->val, NULL, NULL);
            p->next = x;
            x->next = next;
            p = next;
        }
        
        p = head;
        
        while(p != NULL){
           
            if(p->random != NULL) p->next->random = p->random->next;
            p = p->next->next;
        }
        
        p = head;
        Node *new_head = NULL, *s = NULL, *clone = NULL;
        
        while(p != NULL){
            
            next = p->next->next;
            clone = p->next;
            
            if(new_head == NULL){
                new_head = clone;
                s = clone;
            }
            else{
                s->next = clone;
                s = s->next;
            }
            p->next = next;
            p = next;
        }
        return new_head;
    }
};
