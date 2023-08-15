//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        // $ 4^n / n^ (1.5)
        // sigma(T(i))T(n-i-1)
        unsigned const int M = 1000000007;
        long long int ans[n+1];
        for(int i=0;i<=n;i++) ans[i] =0;
        ans[0] = 1;
        ans[1] = 1;
        for(int i = 2;i<=n;i++) {
            for(int j= i-1;j>=0;j--) {
                long long int val = (ans[j] * ans[i-j-1])%M;
                ans[i] = (ans[i] + val)%M;
            }
        }
        return ans[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends