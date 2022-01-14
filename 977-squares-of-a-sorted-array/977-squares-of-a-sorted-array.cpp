class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        vector<int> ans;
        int pt;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                pt=i;break;
            }
        }
        
        int j=pt;
        pt--;
        while(pt>=0 && j<nums.size())
        {
            int a=nums[pt]*nums[pt];
            int b=nums[j]*nums[j];
            if(a<b)
            {
                ans.push_back(a);
                pt--;
            }
            else if(b<a)
            {
                ans.push_back(b);
                j++;
            }
            else
            {
                ans.push_back(a);
                ans.push_back(a);
                j++;
                pt--;
            }
        }
        
        while(j<nums.size()){
            ans.push_back(nums[j]*nums[j]);j++;}
        while(pt>=0){
            ans.push_back(nums[pt]*nums[pt]);pt--;}
        
        return ans;
        
        
        return ans;
        
    }
};