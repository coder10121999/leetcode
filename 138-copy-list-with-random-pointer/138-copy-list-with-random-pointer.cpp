/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         Node* ans=NULL;
        Node* newhead=NULL;
        Node* temp=head;
        map<Node*, Node*> mp;
        while(temp != NULL){
            Node* newnode = new Node(temp->val);
            mp[temp]=newnode;
            if(head == temp){
                ans=newnode;
                newhead=newnode;
            }
            else{
                ans->next=newnode;
                ans=ans->next;
            }
            if(temp->next == NULL)
                newnode->next = NULL;
            temp=temp->next;
            
        }
        
       /* for(auto it=mp.begin();it!=mp.end();it++){
            cout<<it->first->val<<" "<<it->second->val<<"\n";
        }*/
        
        temp=head;
        Node* rand=newhead;
        while(temp != NULL){
            if(temp->random != NULL)
            rand->random= mp[temp->random];
            rand=rand->next;
            temp=temp->next;
        }
            
        
        return newhead;
    }
};