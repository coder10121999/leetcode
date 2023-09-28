class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]%2==0){
                int j=i-1;
                int cur=i;
                while(j>0 && nums[j]%2 == 1){
                     swap(nums[cur],nums[j]);
                     j--;
                     cur--;
                }
                swap(nums[cur],nums[j]);
                
            }
        }
        
        return nums;
        
    }
};