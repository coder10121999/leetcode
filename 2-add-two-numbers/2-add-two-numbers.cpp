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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode* ans=NULL;
        ListNode* head=NULL;
        while(l1 !=NULL && l2!=NULL){
            int a=l1->val;
            int b=l2->val;
            int sum=0;
            sum+=a;
            sum+=b;
            sum+=c;
            ListNode* newnode = new ListNode(sum%10);
            if(ans==NULL){
                ans=newnode;
                head=ans;
            }
            else{
                ans->next = newnode;
                ans=ans->next;
            }
            c=sum/10;  
            l1=l1->next;
            l2=l2->next;
        }
        while(l1 != NULL){
            int sum=l1->val;
            sum+=c;
            ListNode* newnode = new ListNode(sum%10);
            if(ans==NULL){
                ans=newnode;
                head=ans;
            }
            else{
                ans->next = newnode;
                ans=ans->next;
            }
            c=sum/10;  
            l1=l1->next;
        }
        
        while(l2 != NULL){
            int sum=l2->val;
            sum+=c;
            ListNode* newnode = new ListNode(sum%10);
            if(ans==NULL){
                ans=newnode;
                head=ans;
            }
            else{
                ans->next = newnode;
                ans=ans->next;
            }
            c=sum/10;  
            l2=l2->next;
        }
        
        if(c>0){
            ListNode* newnode = new ListNode(c);
            if(ans==NULL){
                ans=newnode;
                head=ans;
            }
            else{
                ans->next = newnode;
            }
            
        }
        
        
        return head;
        
        
    }
};