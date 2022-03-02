class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s=="" && t==""){
            return true;
        }
        
        int i=0;
        int m=s.length();
        int n=t.length();
        
        for(int j=0;j<n;j++){
            if(t[j]==s[i])
             i++;
            if(i==m)
                return true;
        }
        
        return false;
        
        
    }
};