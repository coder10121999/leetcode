//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


void printCorner(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        printCorner(root);
        cout<<endl;
    }
    return 0;
}









// } Driver Code Ends


/* Function to print corner node at each level */

/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/
void printCorner(Node *root)
{
    vector<int> vec;
    //vec.push_back(root->data);
    Node* temp = root;
    vector<vector<int>> adj;
    queue<pair<Node*, int>> q;
    q.push({temp,0});
    //map<int,int> mp;
    while(!q.empty()) {
        Node* front = q.front().first;
        int level = q.front().second;
        
        if(level < adj.size()) {
            adj[level].push_back(front->data);
        } else {
            vector<int> newvec;
            newvec.push_back(front->data);
            adj.push_back(newvec);
        }
        
        if(front->left != NULL)
        q.push({front->left,level+1});
        
        if(front->right != NULL)
        q.push({front->right,level+1});
        
        q.pop();
    }
    for(int i=0;i<adj.size();i++) {
        int m = adj[i].size();
        if(m == 1) vec.push_back(adj[i][0]);
        else {
            vec.push_back(adj[i][0]);
            vec.push_back(adj[i][m-1]);
        }
    }
    
    for(int i=0;i<vec.size();i++) {
        cout<<vec[i]<<" ";
    }
    
// Your code goes here

}