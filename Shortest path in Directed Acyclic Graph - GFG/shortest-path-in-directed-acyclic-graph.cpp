//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

typedef pair<int,int> pii;
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> ans(N, INT_MAX);
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            int wt = edges[i][2];
            adj[a].push_back({b, wt});
        }
        vector<int> vis(N,0);
        pq.push({0,0});
        vis[0] = 1;
        ans[0] = 0;
        
        while(!pq.empty()) {
            
            int dis = pq.top().first;
            int node = pq.top().second;
            vis[node] = 1;
            pq.pop();
            
            for(int i =0;i<adj[node].size();i++) {
                int next = adj[node][i].first;
                int wt = adj[node][i].second;
                if(vis[next] == 0 && dis+wt<= ans[next]) {
                    ans[next] = dis+wt;
                    pq.push({ans[next], next});
                }
            }
        }
         
        for(int i=0;i<N;i++) {
            if(ans[i] == INT_MAX)
            ans[i] = -1;
        }
        return ans;
     }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends