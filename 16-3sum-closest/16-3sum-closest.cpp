class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        if(n<3)
            return 0;
        
        int ans=100000;
        
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int l=j+1;
                int r=n-1;
                int cur=nums[i]+nums[j];
                int rem=target-cur;
                int pt=-1;
                while(l<=r)
                {
                    int mid=l+(r-l)/2;
                    if(nums[mid]<=rem)
                    {
                        pt=mid;
                        l=mid+1;
                    }
                    else
                        r=mid-1;
                }
                
                int sum1=100000,sum2=100000;
                if(pt==-1)
                pt=l;
                
                    sum1=cur+nums[pt];
                    if(pt+1<n)
                    sum2=cur+nums[pt+1];
                
                int x=abs(target-sum1);
                int y=abs(target-sum2);
                int z=abs(target-ans);
                
                if(x<=y && x<=z)
                    ans=sum1;
                else if(y<=x && y<=z)
                    ans=sum2;
                
                
            }
        }
        
        return ans;
        
    }
};