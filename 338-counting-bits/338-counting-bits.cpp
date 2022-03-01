class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        
        for(int i=0;i<=n;i++){
            int z=i;
            int co=0;
            while(z>0){
                if((z%2)&1)
                co++;
                z/=2;
            }
            ans.push_back(co);
        }
        
        return ans;
        
    }
};