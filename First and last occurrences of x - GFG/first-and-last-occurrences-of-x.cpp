//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int> ans, vec;
        for(int i=0;i<n;i++) vec.push_back(arr[i]);
        auto it = lower_bound(vec.begin(), vec.end(), x);
        if(it == vec.end() || (it != vec.end() && *it > x)) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(it-vec.begin());
        auto pt = upper_bound(vec.begin(), vec.end(), x);
        if(pt == vec.end()) {
            ans.push_back(n-1);
            return ans;
        }
        ans.push_back((pt-vec.begin())-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends