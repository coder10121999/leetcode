//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        int lcs[n+1][m+1];
        for(int i=0;i<=n;i++) {
            lcs[i][0] = 0;
        }
        for(int i=0;i<=m;i++) {
            lcs[0][i] = 0;
        }
        int maxv = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(s1[i-1] == s2[j-1]) {
                    lcs[i][j] = 1+ lcs[i-1][j-1];
                } else {
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
                }
                maxv = max(maxv, lcs[i][j]);
            }
        }
        
        // for(int i=0;i<=m;i++) {
        //     for(int j=0;j<=n;j++) {
        //         cout<<lcs[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        return maxv;
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends