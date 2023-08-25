//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n = s.length();
        map<int,int> mp;
        int st = 0;
        int en = 0;
        int ans = -1;
        while(en < n) {
            mp[s[en]-'a']++;
            if(mp.size() == k) {
                ans = max(ans,en-st+1);
            }
            while(mp.size()>k) {
                mp[s[st]-'a']--;
                if(mp[s[st] -'a'] == 0) {
                    mp.erase(s[st]-'a');
                }
                st++;
            }
            en++;
        }
        return ans;
        
        // int arr[n][26];
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<26;j++) {
        //         arr[i][j] = (i > 0) ? arr[i-1][j] : 0;
        //     }
        //     arr[i][s[i]-'a']++;
        // }
        
        // int st = 0;
        // int en = n-1;
        
        // while(st<=en) {
            
        //     int co =0;
        //     for(int i=0;i<26;i++) {
        //         if(arr[en][i] - arr[st][i] > 0) {
        //             co++;
        //         }
        //     }
        //     if(co == k) {
        //         ans = en-st+1;
        //         break;
        //     }

        //     if(co > k) {
        //      st++;                   
        //     }
        // }
        
        // int ans = -1;
        // for(int i=-1;i<n-1;i++) {
            
        //     int checkco=0;
        //     for(int j=0;j<26;j++) {
        //         int x = i >= 0 ? arr[i][j] : 0;
        //         if(arr[n-1][j] - x>0) 
        //         checkco++;
        //     }
            
        //     if(checkco < k) {
        //         break;
        //     }
            
        //     int l = i+1;
        //     int r = n-1;
        //     int ind = -1;
        //     while(l<=r) {
                
        //         int m = (l+r)/2;
                
        //         int co =0;
        //         for(int j=0;j<26;j++) {
        //             int x = i >= 0 ? arr[i][j] : 0;
        //             if(arr[m][j] - x > 0)
        //             co++;
        //         }
        //         if(co <= k) {
        //             ind = m;
        //             l = m + 1;
        //         } else {
        //             r = m - 1;
        //         }
        //     }
        //     if(ind == -1) continue;
            
        //     ans = max(ans, ind -i);
        // }
        // return ans;
        
        
        // a a b a c b e b e b e
        // 1 1 2 2 3 3 4 4 4 4 4
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends