//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    
	    // get max index
	    int l = 0;
	    int r = n-1;
	    int maxi = -1, mini = -1;
	    while(l<=r) {
	        int m = (l + r)/2;
	        if(arr[m] <= x) {
	            maxi = m;
	            l = m + 1;
	        } else {
	            r = m - 1;
	        }
	    }
	    
	    l = 0;
	    r = n -1;
	    while(l<=r) {
	        int m = (l + r)/2;
	        if(arr[m] >= x) {
	            mini = m;
	            r = m - 1;
	        } else {
	            l = m + 1;
	        }
	    }
	    
	    if(mini == -1 || maxi == -1) {
	        return 0;
	    }
	    
	    return maxi - mini + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends