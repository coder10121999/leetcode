class Solution {
public:
    char findTheDifference(string s, string t) {
        int arr[26] = {0};
        for(int i=0;i<s.length();i++) {
            arr[s[i]-'a']++;
        }
        char ans;
        for(int i=0;i<t.length();i++) {
            if(arr[t[i]-'a'] == 0) {
                //cout<<t[i]<<"\n";
                ans = t[i];
                break;
            }
            arr[t[i]-'a']--;
        }
        return ans;
    }
};