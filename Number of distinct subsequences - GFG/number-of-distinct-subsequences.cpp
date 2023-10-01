//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
typedef long long int ll;
#define M 1000000007
class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n = s.length();
	    ll ans = 1;
	    ll sub[n+1] = {0};
	    sub[0] = 1;
	    // val first time  ans= 2*(number of subseq formed till now)
	    // val second time
	    int co[26];
	    memset(co, -1, sizeof(co));
	    for(int i=1;i<=n;i++) {
	        int ind = co[s[i-1]-'a'];
	        if(ind == -1) {
	            sub[i] = (2*sub[i-1])%M;
	        } else {
	            sub[i] = (2*sub[i-1])%M;
	            sub[i] = (sub[i]-sub[ind]+M)%M;
	        }
	        co[s[i-1]-'a'] = i-1;
	    }
	    return sub[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends