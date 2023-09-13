//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	vector<vector<int>> dp;
    
    int comb(int i, int arr[], int n, int sum, int cursum) {
        
        if(cursum>sum) return 0;
        
        if(i== n) {
            if(sum == cursum)
            return 1;
            else
            return 0;
        }
        
        if(dp[i][cursum] != -1)
        return dp[i][cursum];
        
        dp[i][cursum] = (comb(i+1, arr, n, sum, cursum+ arr[i]) + comb(i+1, arr, n, sum, cursum))%1000000007;
        return dp[i][cursum];
    }
    
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // 0 <= i < n
        // 0 <= j <= sum
        
        // sort(arr, arr+n);
        
        // int dp[n][sum+1];
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<=sum;j++) {
        //         dp[i][j] = 0;
        //     }
        // }
        // for(int i=0;i<n;i++)
        // dp[i][0] = 1;
        
        // for(int i=0;i<n;i++) {
        //     for(int j=1;j<=sum;j++) {
        //         if(j== arr[i]) {
        //             dp[i][j] = (dp[i][j] + 1)%1000000007;
        //         }
        //         if(i-1>=0) {
        //             dp[i][j]= (dp[i][j] + dp[i-1][j])%1000000007;
        //         }
        //         if(j-arr[i]>0 && i-1>=0)
        //         dp[i][j] = (dp[i][j] + dp[i-1][j-arr[i]])%1000000007;
        //     }
        // }
        
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<=sum;j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        
        // return dp[n-1][sum];
        for(int i=0;i<n;i++) {
            vector<int> vec;
            for(int j=0;j<=sum;j++) {
                vec.push_back(-1);
            }
            dp.push_back(vec);
        }
        
        return comb(0, arr, n, sum, 0);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends