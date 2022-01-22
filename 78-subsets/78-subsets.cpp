class Solution {
public:
    vector<vector<int>> vec;
    
    void comb(vector<int>& nums,int st,vector<int>& ans)
    {
        int n=nums.size();
        if(st==n){
        vec.push_back(ans);
        return;
        }
        
        ans.push_back(nums[st]);
        comb(nums,st+1,ans);
        ans.pop_back();
        comb(nums,st+1,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        comb(nums,0,ans);
        return vec;
    }
};