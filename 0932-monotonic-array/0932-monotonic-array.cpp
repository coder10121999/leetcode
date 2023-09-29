class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        int st = nums[0];
        bool isInc = true, isDec = true;
        for(int i=1;i<n;i++) {
            if(nums[i]>=st) {
                st=nums[i];
                continue;
            }
            isInc = false;
            break;
        }
        st = nums[0];
        for(int i=1;i<n;i++) {
            if(st>=nums[i]) {
                st = nums[i];
                continue;
            }
            isDec = false;
            break;
        }
        return isDec || isInc;
    }
};