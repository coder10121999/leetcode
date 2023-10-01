class Solution {
public:
    string reverseWords(string s) {
        string word = "";
        string ans = "";
        for(int i=0;i<s.length();i++) {
            if(s[i] == ' ') {
                reverse(word.begin(), word.end());
                if(ans != "") ans+=' ';
                ans+=word;
                word = "";
            } else {
                word+=s[i];
            }
        }
        reverse(word.begin(), word.end());
        if(ans != "") ans+=' ';
        ans+=word;
        return ans;
    }
};