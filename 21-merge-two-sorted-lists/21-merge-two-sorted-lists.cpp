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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
     //   cout<<list1->val;
        ListNode* ans = NULL;
        ListNode* head = ans;
        while(list1 != NULL && list2 !=NULL){
            ListNode* newnode;
           // cout<<list1->val<<" "<<list2->val<<"\n";
            if(list1->val <= list2->val){
                newnode = new ListNode(list1->val);
                list1=list1->next;
            }
            else{
                newnode = new ListNode(list2->val);
                list2=list2->next;
            }
            cout<<newnode->val<<"\n";
            
            if(ans==NULL){
            ans=newnode;
            head=ans;
            }
            else{
            ans->next= newnode;
            ans=ans->next;
            }
        }
        
      //  return head;
        
        while(list1 != NULL){
            ListNode* newnode = new ListNode(list1->val);
                if(ans==NULL){
                    ans=newnode;
                    head=ans;
                }
                else{
                    ans->next= newnode;  
                    ans=ans->next;
                }
            list1=list1->next;
            
        }
        
        while(list2 !=NULL){
            ListNode* newnode = new ListNode(list2->val);
                if(ans==NULL){
                    ans=newnode;
                    head=ans;
                }
                else{
                    ans->next= newnode; 
                
                    ans=ans->next;
                }
            list2=list2->next;
           // ans=ans->next;
        }
        
        return head;
        
        
    }
};