//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int a = arr[0];
        
        if(n==1) return a;
        
        int b = arr[1];
        
        if(n==2) return max(a, b);
        
        int c = arr[2];
        
        if(n==3) return max(b, a+c);
        
        int sum[n];
        sum[0] = a;
        sum[1] = b;
        sum[2] = a+c;
        
        for(int i=3;i<n;i++) {
            sum[i] = max(arr[i]+sum[i-2], arr[i]+sum[i-3]);
        }
        
        return max(sum[n-1], sum[n-2]);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends