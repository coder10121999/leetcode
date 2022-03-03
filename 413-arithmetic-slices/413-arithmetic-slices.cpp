class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        vector<int> diff;
        int val=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            diff.push_back(nums[i]-val);
            val=nums[i];
        }
      //  for(int i=0;i<diff.size();i++)
        //    cout<<diff[i]<<" ";
       // cout<<"\n";
        int ans=0;
        if(diff.size()<2)
            ans=0;
        else
        {
            int prev=diff[0];
            int co=1;
            for(int i=1;i<diff.size();i++){
                if(diff[i]==prev)
                co++;
                else{
                    ans+=(co*(co-1))/2;
                    co=1;
                }
                
                prev=diff[i];
            }
            ans+=(co*(co-1))/2;
            
        }
        
        return ans;
        
        
    }
};