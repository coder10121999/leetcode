//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        int n=str.length();
        map<int,pair<int,int>> mp;
        mp['I'] = {1,1};
        mp['V'] = {5,2};
        mp['X'] = {10,3};
        mp['L'] = {50,4};
        mp['C'] = {100,5};
        mp['D'] = {500,6};
        mp['M'] = {1000,7};
        int ans = 0;
        ans+=mp[str[n-1]].first;
        int curval = mp[str[n-1]].second;
        for(int i=n-2;i>=0;i--) {
            if(mp[str[i]].second >= curval) {
                ans+=mp[str[i]].first;
                curval = mp[str[i]].second;
            } else {
                ans-=mp[str[i]].first;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends