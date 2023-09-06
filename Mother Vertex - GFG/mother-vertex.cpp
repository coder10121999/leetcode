//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int> adj[], int x, int vis[]) {
        vis[x] = 1;
        for(auto it:adj[x]) {
           // cout<<it<<"\n";
            if(vis[it]==0) {
                dfs(adj,it,vis);
            }
        }
    }

	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int vis[V] = {0};
	    int mom = 0;
	    for(int i=0;i<V;i++) {
	        if(vis[i] == 0) {
	            dfs(adj,i,vis);
	            mom = i;
	        }
	    }
	    
	    for(int i=0;i<V;i++) vis[i] = 0;
	    dfs(adj,mom,vis);
	    int co =0;
	    for(int i=0;i<V;i++) {
	        if(vis[i] == 1) co++;
	    }
	    
	    if(co==V) return mom;
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends