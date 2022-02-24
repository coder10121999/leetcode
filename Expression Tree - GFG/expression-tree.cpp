// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    struct node *left;
    struct node *right;

    node(string x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isExpression(string &s) {
    if (s == "+" or s == "-" or s == "*" or s == "/") return true;
    return false;
}



 // } Driver Code Ends
/*The structure of node is as follows
struct node{
    string data;
    node *left;
    node *right;
};
*/

class Solution{
  public:
    /*You are required to complete below method */
    int evalTree(node* root) {
        // Your code here
        string a=root->left->data;
        string b=root->right->data;
        int val1=0,val2=0;
        
        if(a != "+" && a!= "-" && a!="*" && a!="/")
        val1=stoi(a);
        else
        val1=evalTree(root->left);
        
        if(b != "+" && b!= "-" && b!="*" && b!="/")
        val2=stoi(b);
        else
        val2=evalTree(root->right);
        
        string z=root->data;
        if(z=="+")
        root->data=to_string(val1+val2);
        else if(z=="-")
        root->data=to_string(val1-val2);
        else if(z=="*")
        root->data=to_string(val1*val2);
        else
        root->data=to_string(val1/val2);
        
        return stoi(root->data);
        
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int p = 0;
        node *root = new node(s[p++]);
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            node *f = q.front();
            q.pop();
            node *l, *r;
            if (isExpression(f->data)) {
                l = new node(s[p++]);
                r = new node(s[p++]);
                f->left = l;
                f->right = r;
                q.push(l);
                q.push(r);
            }
        }
        Solution obj;
        cout << obj.evalTree(root) << endl;
    }
}
  // } Driver Code Ends