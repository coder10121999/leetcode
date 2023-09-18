class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vec;
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++) {
            int co=0;
            for(int j=0;j<n;j++) {
                if(mat[i][j]==1) co++;
            }
            vec.push_back({co, i});
        }
        sort(vec.begin(), vec.end());
        vector<int> ans;
        for(int i=0;i<k;i++) {
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};