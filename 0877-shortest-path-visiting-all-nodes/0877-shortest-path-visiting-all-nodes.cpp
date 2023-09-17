class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int mask = (1<<n)-1;
        vector<vector<int>> vis(n, vector<int>(mask+1, 0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            q.push({i, (1<<i)});
        }
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0;i<sz;i++) {
                pair<int,int> p = q.front();
                cout<<p.first<<" "<<p.second<<"\n"; 
                q.pop();

                if(p.second == mask) return ans;

                for(auto it: graph[p.first]) {
                    int newmask = p.second | (1<<it);
                    if(vis[it][newmask] == 0) {
                        vis[it][newmask] = 1;
                        q.push({it, newmask});
                    }
                }

            }
            ans++;
        }
        return ans;
    }
};