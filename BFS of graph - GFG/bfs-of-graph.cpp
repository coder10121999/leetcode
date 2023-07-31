//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        // for(int i=0;i<V;i++) {
        //     for(int j=0;j<adj[i].size();j++){
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<int> ans;
        int vis[V] = {0};
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int top = q.front();
            ans.push_back(top);
            q.pop();
            for(int i=0;i<adj[top].size();i++) {
                int node = adj[top][i];
                if(vis[node]==0) {
                    q.push(node);
                    vis[node] = 1;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends