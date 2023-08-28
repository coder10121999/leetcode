//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    
    Node* ans = NULL;
    int curmax = 0;
    Node* traverse(Node* head) {
        if(head == NULL) {
            return head;
        }
        
        
        traverse(head->next);
        
        if(head->data >= curmax) {
            Node* newNode = new Node(head->data);
            newNode->next = ans;
            ans = newNode;
            curmax = head->data;
        }
    }
    
    
    Node *compute(Node *head)
    {
        // your code goes here
        // if(head == NULL) return NULL; 
        // Node* temp = head;
        // Node* ans = NULL;
        // Node* tempHead = NULL;
        // while(temp->next != NULL) {
        //     if(temp->data >= temp->next->data) {
        //         if(tempHead == NULL) {
        //             tempHead = new Node(temp->data);
        //             ans = tempHead;
        //         } else {
        //             tempHead->next = new Node(temp->data);
        //             tempHead = tempHead->next;
        //         }
        //     }
        //     temp = temp->next;
        // }
        // if(tempHead == NULL) {
        //     tempHead = new Node(temp->data);
        //     ans = tempHead;
        // } else {
        //     tempHead->next = new Node(temp->data);
        // }
        // return ans;
        traverse(head);
        return ans;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends