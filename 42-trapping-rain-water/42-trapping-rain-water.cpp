class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        
        int left[n];
        int right[n];
        int maxv=-1;
        for(int i=0;i<n;i++)
        {
            maxv=max(maxv,height[i]);
            left[i]=maxv;   
        }
        maxv=-1;
        for(int i=n-1;i>=0;i--)
        {
            maxv=max(maxv,height[i]);
            right[i]=maxv;
        }
        int newht[n];
        for(int i=0;i<n;i++)
            newht[i]=min(left[i],right[i]);
        
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=abs(newht[i]-height[i]);
        
        return ans;
        
    }
};