class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            int co=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1)
                    co++;
            }
            vec.push_back({co,i});
        }
        vector<int> ans;
        sort(vec.begin(),vec.end());
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        
        return ans;
    }
};