//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    bool isValid(int x, int y, int n, int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }

    bool isBorder(int x, int y, int n, int m) {
        return x == 0 || x == n-1 || y == 0 || y == m-1;
    }
    

    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        int xx[4] = {1,-1,0,0};
        int yy[4] = {0,0,1,-1};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1 && !isBorder(i, j, n, m) && !vis[i][j]) {
                    
                    //cout<<i<<" "<<j<<"\n";
                    
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    
                    int co = 0;
                    
                    vis[i][j] = true;
                    
                    int flag = 0;
                    
                    while(!q.empty()) {
                        
                        int x = q.front().first;
                        int y = q.front().second;
                        
                        //cout<<x<<" "<<y<<"\n";
                        
                        q.pop();
                        
                        if(isBorder(x, y, n, m)) flag = 1;
                        
                        co++;
                        
                        for(int pt=0;pt<4;pt++) {
                            
                            int newx = x+xx[pt];
                            int newy = y+yy[pt];
                            
                            if(isValid(newx, newy, n, m) && grid[newx][newy] == 1 && !vis[newx][newy]) {
                                vis[newx][newy]=true;
                                q.push({newx, newy});
                            }
                        }
                        
                        
                    }
                    
                    if(flag == 0)
                    ans+=co;
                    
                    
                    
                }
            }
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends