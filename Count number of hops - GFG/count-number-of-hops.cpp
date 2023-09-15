//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        long long ans[n+1] = {0};
        ans[1]=1;
        ans[2]=2;
        ans[3]=4;
        for(int i=4;i<=n;i++) {
            ans[i] = (ans[i] + ans[i-1])%1000000007;
            ans[i] = (ans[i] + ans[i-2])%1000000007;
            ans[i] = (ans[i] + ans[i-3])%1000000007;
        }
        return ans[n];
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends