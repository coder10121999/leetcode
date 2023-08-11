//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int> arr;
       arr.push_back(a[0]);
       for(int i=1;i<n;i++) {
           int num = a[i];
        //   cout<<"To add:"<<num<<"\n";
        //   for(int k=0;k<arr.size();k++) {
        //       cout<<arr[k]<<" ";
        //   }
        //   cout<<"\n";
           if(a[i]>arr.back()) {
               arr.push_back(a[i]);
           } else {
               int l = 0;
               int r = arr.size() - 1;
               int pos = -1;
               while(l<=r) {
                   int m = (l+r)/2;
                   if(arr[m] >= a[i]) {
                       pos = m;
                       r = m - 1;
                   } else {
                       l = m + 1;
                   }
               }
               arr[pos] = a[i];
           }
        //   cout<<"AfterInsertion: \n";
        //   for(int k=0;k<arr.size();k++) {
        //       cout<<arr[k]<<" ";
        //   }
        //   cout<<"\n";
       }
       
       return arr.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends