class Solution {
public:
    int rob(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int arr[n];
        arr[0]=nums[0];
        for(int i=1;i<n;i++){
            arr[i]=nums[i];
            int z=0;
            for(int j=i-2;j>=0;j--){
                z=max(z,arr[j]);
            }
            arr[i]+=z;
            cout<<arr[i]<<" ";
        }
        
        if(n>=2)
            ans=max(ans,arr[n-2]);
        ans=max(ans,arr[n-1]);
        
        return ans;
        
    }
};