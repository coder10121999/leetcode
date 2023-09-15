class Solution {
public:

    int manhatdist(vector<int> &a, vector<int> &b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, int>> adj[n];
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int wt = manhatdist(points[i], points[j]);
                adj[i].push_back({wt, j});
                adj[j].push_back({wt, i});
            }
        }


        bool mstSet[n];
        for(int i=0;i<n;i++) {
            mstSet[i]=false;
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        int ans = 0;
        while(!pq.empty()) {
            int wt = pq.top().first;
            int x = pq.top().second;

            pq.pop();

            if(mstSet[x] == true) continue;
            ans+=wt;
            mstSet[x] = true;
            for(auto it: adj[x]) {
                if(mstSet[it.second] == false) {
                    pq.push(it);
                }
            }
        }
        return ans;
    }
};