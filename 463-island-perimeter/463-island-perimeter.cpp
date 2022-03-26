class Solution {
public:
    int ans=0;
    void dfs(int x,int y,vector<vector<int>>& grid, vector<vector<int>>& vis, int n,int m){
        
        vis[x][y]=1;
        int co=4;
        if(x-1>=0){
            if(grid[x-1][y]==1)
            co--;
        }
        if(x-1>=0 && vis[x-1][y]==0 && grid[x-1][y]==1)
            dfs(x-1,y,grid,vis,n,m);
        if(y-1>=0 && grid[x][y-1]==1)
            co--;
        if(y-1>=0 && vis[x][y-1]==0 && grid[x][y-1]==1)
            dfs(x,y-1,grid,vis,n,m);
        if(x+1<n && grid[x+1][y]==1)
            co--;
        if(x+1<n && vis[x+1][y]==0 && grid[x+1][y]==1)
            dfs(x+1,y,grid,vis,n,m);
        if(y+1<m && grid[x][y+1]==1)
            co--;
        if(y+1<m && vis[x][y+1]==0 && grid[x][y+1]==1)
            dfs(x,y+1,grid,vis,n,m);
        
        ans+=co;
        
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vis[i].push_back(0);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)
                    dfs(i,j,grid,vis,n,m);
                }
            }
        
    
       cout<<ans<<"\n";
       return ans;
       //turn ans;
        
    }
};