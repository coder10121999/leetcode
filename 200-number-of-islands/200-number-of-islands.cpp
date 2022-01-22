class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& vis,vector<vector<char>>& grid,int m,int n){
        vis[x][y]=1;
        if(x-1>=0 && vis[x-1][y]==0 && grid[x-1][y]=='1')
            dfs(x-1,y,vis,grid,m,n);
        if(y-1>=0 && vis[x][y-1]==0 && grid[x][y-1]=='1')
            dfs(x,y-1,vis,grid,m,n);
        if(x+1<m && vis[x+1][y]==0 && grid[x+1][y]=='1')
            dfs(x+1,y,vis,grid,m,n);
        if(y+1<n && vis[x][y+1]==0 && grid[x][y+1]=='1')
            dfs(x,y+1,vis,grid,m,n);
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
      /*  for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                vis[i][j]=0;
        }*/
        int co=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    if(vis[i][j]==0)
                    {
                        co++;
                        dfs(i,j,vis,grid,m,n);
                    }
                }
            }
        }
        
        return co;
        
        
    }
};