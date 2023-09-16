class Solution {
public:

    bool isValid(int a, int b, int n , int m) {
        return a>=0 && a<n && b>=0 && b<m;
    }

    int getDis(int a, int b, int c, int d , vector<vector<int>>& heights) {
        return abs(heights[a][b] - heights[c][d]);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        //cout<<n<<" "<<m<<"\n";

        int xx[4] = {-1, 0, 1, 0};
        int yy[4] = {0, -1, 0, 1};

        // priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        // pq.push({0, {0, 0}});
        // map<pair<int,int> , pair<int,int>> parent;

        // bool mstSet[n][m];
        // int dist[n][m];
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         mstSet[i][j] = false;
        //         dist[i][j] = INT_MAX;
        //     }
        // }
        // dist[0][0] = 0;
        // int maxv = 0;

        // while(!pq.empty()) {
        //     int wt = pq.top().first;
        //     int x = pq.top().second.first;
        //     int y = pq.top().second.second;

        //     pq.pop();

        //     if(mstSet[x][y] == true) continue;

        //     maxv = max(maxv, wt);
        //     mstSet[x][y] = true;

        //     for(int i=0;i<4;i++) {
        //         int newx = xx[i]+x;
        //         int newy = yy[i]+y;
        //         if(isValid(newx, newy, n, m) && mstSet[newx][newy] == false) {
        //             int newDistance = abs(heights[x][y] - heights[newx][newy]);
        //             if(newDistance < dist[newx][newy]) {
        //                 dist[newx][newy] = newDistance;
        //                 parent[{newx,newy}] = {x,y};
        //                 pq.push({newDistance, {newx, newy}});
        //             }
        //         }
        //     }

        // }

        // pq.push({0, {0, 0}});
        // map<pair<int,int> , pair<int,int>> parent;

        // bool mstSet[n][m];
        // int dist[n][m];
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         mstSet[i][j] = false;
        //         dist[i][j] = INT_MAX;
        //     }
        // }
        // dist[0][0] = 0;
        // int ans = 0;




        int l = 0;
        int r = 1000005;
        int ans = 0;
        while(l<=r) {

            int mid = (l + r)/2;
            //cout<<mid<<"\n";
            bool vis[n][m];
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    vis[i][j] =false;
                }
            }

            queue<pair<int, int>> q;
            q.push({0, 0});
            vis[0][0] = true;
            
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;

                //cout<<x<<" "<<y<<"\n";

                q.pop();

                if(x == n-1 && y == m-1) 
                break;

                //cout<<x<<" "<<y<<"\n";
                
                for(int i=0;i<4;i++) {
                    int newx = xx[i]+x;
                    int newy = yy[i]+y;
                    if(isValid(newx, newy, n, m) && vis[newx][newy] == false) {
                        int dist = getDis(x,y,newx,newy,heights);
                       // cout<<dist<<" -Dist\n";
                        if(dist <= mid) {
                            vis[newx][newy]=true;
                            q.push({newx, newy});
                        }
                    }
                }
            }

            if(vis[n-1][m-1]) {
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return ans;
    }
};