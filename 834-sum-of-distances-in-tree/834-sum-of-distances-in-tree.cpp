class Solution {
public:
    void dfs(int x,vector<int> adj[],int vis[],int par[],int arr[],int brr[])
    {
        vis[x]=1;
        int co=1;
        int val=0;
        for(auto it:adj[x])
        {
            if(vis[it]==0)
            {
                par[it]=x;
                dfs(it,adj,vis,par,arr,brr);
                co+=brr[it];
                val+=(arr[it]+brr[it]);
            }
        }
        arr[x]=val;
        brr[x]=co;
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> ans;
        int fans[N];
        
        vector<int> adj[N];
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int par[N];
        par[0]=-1;
        int vis[N];
        int newvis[N];
        for(int i=0;i<N;i++)
            vis[i]=0,newvis[i]=0;
        int arr[N],brr[N];
        dfs(0,adj,vis,par,arr,brr);
        
        for(int i=0;i<N;i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        for(int i=0;i<N;i++)
            cout<<brr[i]<<" ";
        cout<<"\n";
        
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int x=q.front();
            if(par[x]==-1)
                fans[x]=arr[x];
            else
            {
               fans[x]=(arr[par[x]]+N)-2*brr[x];
               arr[x]=fans[x];
            }
            
            newvis[x]=1;
            for(auto it:adj[x])
            {
                if(newvis[it]==0)
                    q.push(it);
            }
            q.pop();
             
        }
        
        for(int i=0;i<N;i++)
            ans.push_back(fans[i]);
        
        return ans;
        
        
    }
};