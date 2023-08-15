//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int co0 =0, co1= 0;
        int count1 =0;
        int fc0 = 0, fc1 = 0;
        for(int i=0;i<n;i++) {
            if(a[i] == 1) 
            count1++;
        }
        int maxv = 0;
        for(int i=0;i<n;i++) {
            if(a[i] == 0) {
                co0++;
            } else {
                co1++;
            }
            if(co0 <= co1) {
                co0 = 0;
                co1 = 0;
            }
            //cout<<co0<<" "<<co1<<"\n";
            maxv = max(maxv, co0 - co1);
            if(maxv == co0 -co1) {
                fc0 = co0;
                fc1 = co1;
            }
        }
        return count1 + (fc0 - fc1);
        // for each subarray co0 - co1 is added to array 
        /// each subarray should start and end with 0
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends