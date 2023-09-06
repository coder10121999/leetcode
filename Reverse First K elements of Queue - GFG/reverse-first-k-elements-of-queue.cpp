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
    int n = q.size();
    int left = n-k;
    stack<int> st;
    while(!q.empty()) {
        if(k>0) {
            st.push(q.front());
        } else {
            break;
        }
        k--;
        q.pop();
    }
    while(!st.empty()) {
        q.push(st.top());
        st.pop();
    }
    while(left--) {
        q.push(q.front());
        q.pop();
    }
    return q;
}