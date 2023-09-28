class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n=nums.size();
        int st = 0;
        int en = n-1;
        while(st<en) {
            if(nums[st]%2==1 && nums[en]%2==0) {
                swap(nums[st], nums[en]);
                st++;
                en--;
            } else if(nums[st]%2==0) {
                st++;
            } else {
                en--;
            }
        }
        // for(int i=0;i<n;i++) {

        // }
        // for(int i=1;i<n;i++){
        //     if(nums[i]%2==0){
        //         int j=i-1;
        //         int cur=i;
        //         while(j>0 && nums[j]%2 == 1){
        //              swap(nums[cur],nums[j]);
        //              j--;
        //              cur--;
        //         }
        //         swap(nums[cur],nums[j]);
                
        //     }
        // }
        
        return nums;
        
    }
};