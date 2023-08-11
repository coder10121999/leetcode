//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long int count(int coins[], int N, int sum) {

        // code here.
        if(sum == 0) {
            return 1; 
        }
        sort(coins, coins+N);
        long long int dp[sum+1][N+1];
        for(int i=0;i<=sum;i++) {
            for(int j=0;j<=N;j++) {
                dp[i][j] = 0;
            }
        }
        for(int i=1;i<=sum;i++) {
            for(int j=1;j<=N;j++) {
                int val = coins[j-1];
                if(val== i) {
                    dp[i][j] = dp[i][j-1] + 1;
                } else if(val <i) {
                    dp[i][j] = dp[i][j-1] + dp[i-val][j];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[sum][N];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends