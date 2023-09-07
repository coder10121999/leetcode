//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>> q;
        q.push({start,0});
        int vis[100000] = {0};
        vis[start] = 1;
        while(!q.empty()) {
            int z = q.front().first;
            int steps = q.front().second;
            
            if(z == end) return steps;
    
            for(int i=0;i<arr.size();i++) {
                int val = (z*arr[i])%100000;
                if(vis[val] == 0) {
                    vis[val] = 1;
                    q.push({val, steps+1});
                }
            }
            q.pop();
        }
        
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends