class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        vector<int> ans;
        int st=-1,en=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>=target)
            {
              st=mid;
              r=mid-1;
            }
            else
                l=mid+1;
        }
        
        l=0;
        r=nums.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]<=target)
            {
                en=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        
        if(st!=-1 && nums[st]!=target)
            st=-1;
        
        if(en!=-1 && nums[en]!=target)
            en=-1;
            
        ans.push_back(st);
        ans.push_back(en);
        
        return ans;
    }
};