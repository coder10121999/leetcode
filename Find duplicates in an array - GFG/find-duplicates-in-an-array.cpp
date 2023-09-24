//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        set<int> ans;
        for(int i=0;i<n;i++) arr[i]++;
        for(int i=0;i<n;i++) {
            int val = abs(arr[i]);
            if(arr[val-1] < 0) {
                ans.insert(val-1);
            } else {
                arr[val-1] = -arr[val-1];
            }
        }
        vector<int> vec;
        for(auto it: ans) {
            vec.push_back(it);
        }
        if(vec.empty()) vec.push_back(-1);
        return vec;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends