class Solution {
public:
    int fun(int x,vector<int>& piles)
    {
        int n=piles.size();
        int co=0;
        for(int i=0;i<n;i++)
        {
            if(piles[i]%x==0)
                co+=piles[i]/x;
            else
                co+=(piles[i]/x)+1;
        }
        return co;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n=piles.size();
        
        int maxv=INT_MIN;
        for(int i=0;i<n;i++)
            maxv=max(maxv,piles[i]);
        
        int l=1;
        int r=maxv;
        int ans=maxv;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(fun(mid, piles) > h)
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }
        }
        
        return ans;
        
    }
};