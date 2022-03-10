class Solution {
public:
    struct Node{
        int value=-1;
    };
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        
        int l=-1,r=0;
        int n=s.length();
        int ans=1;
        map<int,Node> last;
        while(l<n && r<n){
            if(last[s[r]].value>=l)
                l=last[s[r]].value+1;
            last[s[r]].value=r;
            ans=max(ans,r-l+1);
            cout<<s.substr(l,r-l+1)<<"\n";
            r++;
        }
        
        return ans;
        
    }
};