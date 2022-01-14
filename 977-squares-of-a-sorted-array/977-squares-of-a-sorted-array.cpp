class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        mp[nums[i]*nums[i]]++;
        vector<int> ans;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            for(int i=0;i<it->second;i++)
                ans.push_back(it->first);
        }
        
        return ans;
        
    }
};