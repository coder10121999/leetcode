/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int f=0;
        while(slow != NULL && fast!=NULL){
            if(slow == fast && f!=0)
                return true;
            slow=slow->next;
            if(fast->next != NULL)
            fast=fast->next->next;
            else
                fast=NULL;
            f=1;
            
        }
        
        return false;
        
    }
};