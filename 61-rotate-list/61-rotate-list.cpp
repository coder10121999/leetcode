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
    ListNode* rotateRight(ListNode* head, int k) {
        
        int len=0;
        ListNode* temp=head;
        while(temp != NULL){
            len++;
            temp=temp->next;
        }
        if(len==0 || k%len==0)
            return head;
        
        k=k%len;
        
        temp=head;
        int z=len-k;
        ListNode* breaknode;
        while(temp != NULL && z>0){
            breaknode=temp;
            temp=temp->next;
            z--;
        }
        
        ListNode* newhead=temp;
        ListNode* ans=newhead;
        breaknode->next = NULL;
        
        while(true){
            if(newhead->next==NULL){
                newhead->next = head;
                break;
            }
            newhead=newhead->next;
        }
        
        
        return ans;
        
        
    }
};