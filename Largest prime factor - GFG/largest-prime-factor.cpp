//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int largestPrimeFactor(int N){
        // code here
        long long int ans = N;
        int z = 2;
        while(z<=(int)sqrt(N)) {
            if(N%z == 0) {
                N /= z;
                z = 2;
            } else {
                z++;
            }
        }
        ans = N;
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends