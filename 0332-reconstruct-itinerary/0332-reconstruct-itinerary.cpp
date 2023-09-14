class Solution {
public:

    void dfs(map<string, vector<pair<string, int>>> &mp, vector<string> &ans, string x) {
      for(int i=mp[x].size()-1;i>=0;i--) {
        if(mp[x][i].second == 0) {
          mp[x][i].second = 1;
          dfs(mp, ans, mp[x][i].first);
        }
      }
       ans.push_back(x);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        map<string, vector<pair<string, int>>> mp;
        for(int i=0;i<n;i++) {
          string s1 = tickets[i][0];
          string s2 = tickets[i][1];
          mp[s1].push_back({s2,0});
        }
        for(auto it= mp.begin();it!= mp.end();it++) {
          string z = it->first;
          sort(mp[z].rbegin(), mp[z].rend());
        }
        // for(auto it= mp.begin();it!= mp.end();it++) {
        //   string x = it->first;
        //   cout<<x<<"\n";
        //   vector<pair<string, int>> cur;
        //   cur = mp[x];
        //   for(int i=0;i<cur.size();i++) {
        //     cout<<cur[i].first<<" "<<cur[i].second<<"\n";
        //   }
        //   cout<<"\n";
        //   cout<<"\n";
        // }
        vector<string> ans;
        dfs(mp, ans, "JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};