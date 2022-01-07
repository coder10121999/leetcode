class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        int a,b;
        for(int i=0;i<nums.size();i++)
        {
            a=nums[i];
            mp[a]--;
            int z=target-a;
            if(mp[z]>0)
            {
                b=z;
                break;
            }
            mp[a]++;
        }
        
        int inda=-1,indb=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==a && indb!=i)
                inda=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==b && i!=inda)
                indb=i;
        }
        
        vector<int> ans;
        ans.push_back(inda);
        ans.push_back(indb);
        return ans;
        
        
    }
};