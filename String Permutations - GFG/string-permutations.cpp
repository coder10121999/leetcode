//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> ans;
    void perm(string s, int n, string cur, int vis[]) {
        if(cur.length()==n) {
            ans.push_back(cur);
            return;
        }
        
        for(int j=0;j<n;j++) {
            if(vis[j] == 0) {
                vis[j] = 1;
                perm(s, n, cur+s[j], vis);
                vis[j] = 0;
            }
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        int n = S.length();
        int vis[n] = {0};
        perm(S,n,"",vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends