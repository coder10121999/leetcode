//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        long long cursum = 0;
        int left = 0;
        int right = -1;
        vector<int> ans;
        for(int i=0;i<n;i++) {
            cursum += arr[i];
            right++;

            while(cursum > s && left < right) {
                cursum -= arr[left];
                left++;
            }
            
            // cout<<cursum<<" "<<left<<" "<<right<<"\n";
            if(cursum == s) {
                ans.push_back(left+1);
                ans.push_back(right+1);
                break;
            }
            
        }
        //    cout<<left<<" "<<right<<"\n";
        if(ans.empty()) {
            ans.push_back(-1);
        }
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
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends