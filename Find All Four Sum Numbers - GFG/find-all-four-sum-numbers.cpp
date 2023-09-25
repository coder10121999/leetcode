//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    
    static bool comp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) {
            if(a[1] == b[1]) {
                if(a[2] == b[2]) {
                    return a[3] < b[3];
                }
                return a[2] < b[2];
            }
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }

    vector<vector<int> > fourSum(vector<int> &arr, int K) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        map<int,int> mp;
        int n = arr.size();
        vector<vector<int>> ans;
        if(n<4) return ans;
        
    
        for(int i=0;i<n-3;i++) {
            for(int j=i+1;j<n-2;j++) {
                
                int sum = arr[i]+arr[j];
                int z = K-sum;
                int l = j+1;
                int r = n-1;
                while(l<r) {
                    int val = arr[l]+arr[r];
                    if(val > z) r--;
                    else if(val < z) l++;
                    else {
                        vector<int> vec;
                        vec.push_back(arr[i]);
                        vec.push_back(arr[j]);
                        vec.push_back(arr[l]);
                        vec.push_back(arr[r]);
                        ans.push_back(vec);
                        int a = arr[l];
                        int b = arr[r];
                        while(l<r && arr[l] == a) l++;
                        while(l<r && arr[r] == b) r--;
                    }
                }
                int d = arr[j];
                while(j<n-2 && arr[j+1] == d) j++;
            }
            int c = arr[i];
            while(i<n-3 && arr[i+1] == c) i++;
        }
        
        sort(ans.begin(), ans.end(), comp);
        
        
        // for(auto it : st) {
        //     vector<int> vec;
        //     vec.push_back(it.first);
        //     vec.push_back(it.second.first);
        //     vec.push_back(it.second.second.first);
        //     vec.push_back(it.second.second.second);
        //     ans.push_back(vec);
        // }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends