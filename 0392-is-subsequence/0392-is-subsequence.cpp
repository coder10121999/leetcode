class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s=="") return true;
        int k = 0;
        for(int i=0;i<t.length();i++) {
            if(s[k] == t[i]) {
                k++;
            }
            if(k==s.length()) return true;
        }

        return false;
        
    }
};