class Solution {
public:
    void dfs(int row,int vis[],vector<vector<int>>& grid)
    {
        int n=grid.size();
        vis[row]=1;
        for(int i=0;i<n;i++)
        {
            if(i!=row && vis[i]==0 && grid[row][i]==1){
                dfs(i,vis,grid);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        int vis[n];
        for(int i=0;i<n;i++)
            vis[i]=0;
        
        int co=0;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                co++;
             dfs(i,vis,isConnected);
            }
        }
        
        return co;
        
    }
};