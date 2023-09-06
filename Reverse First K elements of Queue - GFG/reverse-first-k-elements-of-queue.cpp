//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int> qu;
    queue<int> st;
    while(!q.empty()) {
        if(k>0) {
            qu.push(q.front());
        } else {
            st.push(q.front());
        }
        k--;
        q.pop();
    }
    // while(!qu.empty()) {
    //     cout<<qu.front()<<" ";
    //     qu.pop();
    // }
    // cout<<"\n";
    while(!qu.empty()) {
        q.push(qu.top());
        qu.pop();
    }
    while(!st.empty()) {
        q.push(st.front());
        st.pop();
    }
    return q;
}