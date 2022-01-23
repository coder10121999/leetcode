class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> num;
        for(int i=2;i<=9;i++)
        {
            int st=1;
            for(int j=0;j<10-i;j++)
            {
                int ans=0;
                for(int k=st;k<st+i;k++)
                {
                    ans*=10;
                    ans+=k;
                }
                num.push_back(ans);
                st++;
            }
                
        }
        
        vector<int> fans;
        for(int i=0;i<num.size();i++)
        {
            if(num[i]>=low && num[i]<=high)
                fans.push_back(num[i]);
        }
        
        return fans;
        
    }
};