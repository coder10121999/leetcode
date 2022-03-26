class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        
        string ans="";
        int n=strs.size();
        string first=strs[0];
        //null check here
        int m=first.length();
        for(int i=0;i<m;i++){
            char ch=first[i];
            int co=0;
            for(int j=1;j<n;j++){
                string z=strs[j];
                //null check here
                if(i<z.length() && z[i]==ch)
                    co++;
            }
            if(co==n-1)
                ans+=ch;
            else
                break;
        }
        return ans;
        
    }
};

