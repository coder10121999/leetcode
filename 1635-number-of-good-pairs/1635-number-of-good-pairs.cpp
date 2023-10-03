class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> mp;
        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        for(auto it: mp) {
            ans+=((it.second)*(it.second-1))/2;
        }
        return ans;
    }
};