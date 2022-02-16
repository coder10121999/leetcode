/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        
        
        ListNode* prev=NULL;
        ListNode* cur =head;
        
        ListNode* new_head = NULL;
        if(head->next !=NULL)
        new_head = head->next;
        ListNode* nex = NULL;
        while(cur !=NULL){
            nex = cur->next;
            if(prev!=NULL && nex !=NULL)
                prev->next = nex;
            
            if(nex!=NULL){
                cur->next = nex->next;
                nex->next = cur;
            }
                prev = cur;
            
            cur=cur->next;
                
        }
        if(new_head != NULL)
        return new_head;
        
        return head;
    }
};