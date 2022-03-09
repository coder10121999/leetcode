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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* prev=NULL;
        ListNode* temp=head;
        ListNode* next=NULL;
        int f=0;
        while(temp != NULL){
            next = temp->next;
            if(next==NULL)
                break;
            if(temp->val == next->val){
                temp=temp->next;
                f=1;
                continue;
            }
            else{
                if(f==1){
                if(prev==NULL)
                    head=next;
                else
                prev->next=next;
                
                f=0;
                }
                else
                prev=temp;
                
                temp=next;
            }
            
                
        }
        if(f==1){
            if(prev!=NULL)
            prev->next=NULL;
            else
                head=prev;
        }
        return head;
        
    }
};