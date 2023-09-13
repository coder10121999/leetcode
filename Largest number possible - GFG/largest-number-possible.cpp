//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        int z = 9 * N;
        if(z<S) return "-1";
        if(S == 0 && N > 1) return "-1";
        string ans = "";
        for(int i=0;i<N;i++) {
            int x = min(S, 9);
            ans += to_string(x);
            S-=x;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends