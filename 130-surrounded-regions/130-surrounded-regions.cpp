class Solution {
public:
    int f=0;
    vector<pair<int,int>> tochange;
    void dfs(int x,int y,int m,int n,vector<vector<char>>& board,vector<vector<int>>& vis)
    {
        tochange.push_back({x,y});
        vis[x][y]=1;
        if(x-1 < 0 || y-1 < 0 || x+1==m || y+1==n)
        {
            f=1;
        }
        if((x-1)>=0 && board[x-1][y]=='O' && vis[x-1][y]==0)
        dfs(x-1,y,m,n,board,vis);
        if((x+1)< m && board[x+1][y]=='O' && vis[x+1][y]==0)
        dfs(x+1,y,m,n,board,vis);
        if((y-1)>=0 && board[x][y-1]=='O' && vis[x][y-1]==0)
        dfs(x,y-1,m,n,board,vis);
        if((y+1)<n && board[x][y+1]=='O' && vis[x][y+1]==0)
        dfs(x,y+1,m,n,board,vis);
        
    }
    void solve(vector<vector<char>>& board) {
       int m=board.size();
       int n=board[0].size();
       vector<vector<int>> vis;
       vector<vector<int>> change;
        for(int i=0;i<m;i++)
        {
            vector<int> vec;
            for(int j=0;j<n;j++)
                vec.push_back(0);
            vis.push_back(vec);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                {
                    if(vis[i][j]==0)
                    {
                        f=0;
                        tochange.clear();
                        dfs(i,j,m,n,board,vis);
                        
                       
                        
                        if(f==0)
                        {
                            for(int k=0;k<tochange.size();k++)
                                board[tochange[k].first][tochange[k].second]='X';
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<board[i][j];
            cout<<"\n";
        }
        
        
        
        
        
        
        
    }
};