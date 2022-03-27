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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        map<int,int> mp;
        ListNode* newhead=head;
        int sum=0;
       
        
        while(newhead!=NULL){
            sum+=newhead->val;
            if(sum==0)
            {
                head=newhead->next;
                newhead=head;
            }
            else
                newhead=newhead->next;
        }
        
        newhead=head;
        sum=0;
         while(newhead!=NULL){
            sum+=newhead->val;
            mp[sum]++;
            newhead=newhead->next;
        }
        
        
        newhead=head;
        sum=0;
        //int f=0;
        while(newhead!=NULL){
            int z=newhead->val;
            
            sum+=z;
            
            if(mp[sum]>1)
            {
                ListNode* temp=newhead;
                temp=temp->next;
                int curval=sum+temp->val;
                mp[curval]--;
              //  cout<<sum<<"\n";
                while(temp!=NULL && mp[sum]!=1){
                    
                    temp=temp->next;
                    if(temp!=NULL)
                        curval+=temp->val;
                    //mp[curval]--;
                    if(curval==sum)
                        mp[sum]--;
                    else
                        mp[curval]--;
                    
                  //  cout<<curval<<" "<<sum<<" "<<mp[sum]<<"\n";
                    
                }
                
                newhead->next=temp->next;
               
            }
        
            newhead=newhead->next;
               // f=0;
            
        }
        
        return head;
    }
};