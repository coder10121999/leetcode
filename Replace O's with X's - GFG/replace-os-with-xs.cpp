//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isBoundary(int x, int y, int n, int m) {
        return x == 0 || x == n-1 || y == 0 || y == m-1;
    }

    bool isValid(int x, int y, int n, int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> vec = mat;
        vector<vector<int>> vis;
        for(int i=0;i<n;i++) {
            vector<int> newvis;
            for(int j=0;j<m;j++) {
                newvis.push_back(0);
            }
            vis.push_back(newvis);
        }
        vector<vector<pair<int,int>>> shouldChange;
        int xco[4] = {-1,0,1,0};
        int yco[4] = {0,-1,0,1};
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 'O' && vis[i][j] == 0) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    int f = 0;
                    vector<pair<int,int>> pointsToChange;
                    while(!q.empty()) {
                        
                        int x = q.front().first;
                        int y = q.front().second;
                        pointsToChange.push_back({x,y});
                        
                        if(isBoundary(x,y,n,m)) {
                            f = 1;
                        }
                        
                        for(int k=0;k<4;k++) {
                            int newx = x+xco[k];
                            int newy = y+yco[k];
                            if(isValid(newx, newy, n, m) && vis[newx][newy] == 0 && mat[newx][newy] == 'O') {
                                vis[newx][newy] = 1;
                                q.push({newx, newy});
                            }
                        }
                        
                        
                        q.pop();
                        
                    }
                    
                    if(f==0) {
                        shouldChange.push_back(pointsToChange);
                    }
                }
            }
        }
        
        for(int i=0;i<shouldChange.size();i++) {
            for(int j=0;j<shouldChange[i].size();j++) {
                int x = shouldChange[i][j].first;
                int y = shouldChange[i][j].second;
                
                vec[x][y] = 'X';
            }
        }
        
        return vec;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends