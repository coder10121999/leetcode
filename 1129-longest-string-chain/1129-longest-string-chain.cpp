class Solution {
public:
    // check if a is predecessor of b
    bool isPredecessor(string a, string b) {
        int n = a.length();
        int m = b.length();
        if(m != n+1) return false;
        
        int k = 0;
        for(int i=0;i<m;i++) {
            if(a[k] == b[i]) {
                k++;
            }
            if(k == a.length()) return true;
        }

        return false;
    }

    static bool comp(string s1, string s2) {
        if(s1.length() == s2.length()) return s1 < s2;
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), comp);
        int n = words.size();
        int len[n];
        for(int i=0;i<n;i++) len[i]=0;
        len[0]++;
        for(int i=1;i<n;i++) {
            string ss = words[i];
            len[i]++;
            for(int j=0;j<i;j++) {
                if(isPredecessor(words[j], ss) && len[i] < len[j] + 1) {
                    len[i] = len[j]+1;
                }
            }
        }

        int maxv = 0;
        for(int i=0;i<n;i++) {
            maxv = max(maxv, len[i]);
        }
        return maxv;
    }
};