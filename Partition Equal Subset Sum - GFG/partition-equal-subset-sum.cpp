//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    vector<vector<int>> dp;

    bool comb(int i, int n, int sum, int target, int arr[]) {
        if(i==n) return sum == target;
        
        if(sum>target) return false;
        
        if(dp[i][sum] != -1)
        return dp[i][sum];
        
        bool ans = comb(i+1, n, sum+arr[i], target, arr) || comb(i+1, n, sum, target, arr);
        dp[i][sum] = ans;
        return ans;
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        
        int target = 0;
        for(int i=0;i<N;i++) {
            target+=arr[i];
        }
        
        if(target%2==1) return 0;
        target/=2;
        
        for(int i=0;i<N;i++) {
            vector<int> cur;
            for(int j=0;j<=target;j++) {
                cur.push_back(-1);
            }
            dp.push_back(cur);
        }
        
        return comb(0, N, 0, target, arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends