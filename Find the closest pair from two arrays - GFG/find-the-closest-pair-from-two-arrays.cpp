//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        sort(arr, arr+n);
        sort(brr, brr+m);
        vector<int> ans;
        int nearest = INT_MAX;
        for(int i=0;i<n;i++) {
                int z = x-arr[i];
                
                int l =0;
                int r = m-1;
                while(l<=r) {
                    int mid = (l+r)/2;
                    if(abs(z-brr[mid]) < nearest) {
                        nearest = abs(z-brr[mid]);
                        ans.clear();
                        // cout<<arr[i]<<brr[mid]<<"\n";
                        ans.push_back(arr[i]);
                        ans.push_back(brr[mid]);
                    }
                    if(z>=brr[mid]) {
                        l = mid+1;
                    } else {
                        r = mid-1;
                    }
                }
        }
        // cout<<ans[0]<<" "<<ans[1]<<"\n";
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends