//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> ans;
        
        int n= string_list.size();
        int vis[n] = {0};
        
        for(int i=0;i<n;i++) {
            if(vis[i] == 0) {
                vector<string> cur;
                string s1 = string_list[i];
                cur.push_back(s1);
                vis[i] = 1;
                for(int j=i+1;j<n;j++) {
                    string s2 = string_list[j];
                    if(vis[j] == 0 && s2.length() == s1.length()) {
                        map<char,int> mp;
                        for(int k=0;k<s1.length();k++) {
                            mp[s1[k]]++;
                            mp[s2[k]]--;
                        }
                        
                        int f = 0;
                        for(auto it = mp.begin();it!= mp.end();it++) {
                            if(it->second != 0) {
                                f =1;
                                break;
                            }
                        }
                        
                        if(f==0) {
                            cur.push_back(s2);
                            vis[j] = 1;
                        }
                    }
                }
                ans.push_back(cur);
            }
        }
        
        sort(ans.begin(), ans.end());
        
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
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends