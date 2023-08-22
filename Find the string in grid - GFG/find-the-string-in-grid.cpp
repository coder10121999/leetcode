//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


    bool isValid(int x, int y, int m, int n) {
        return x>=0 && x<m && y>=0 && y<n;
    }

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int m = grid.size();
	    int n = grid[0].size();
	    
	    int sz = word.length();
	    vector<vector<int>> ans;
	    int x[8] = {-1,-1,-1,0,0,1,1,1};
	    int y[8] = {-1,0,1,-1,1,-1,0,1};
	    for(int i=0;i<m;i++) {
	        for(int j=0;j<n;j++) {
	            
	            int xco = i;
	            int yco = j;
	            
	            for(int k=0;k<8;k++) {
	                
	                bool found = true;
	                for(int w=0;w<sz;w++) {
	                    int newx = xco + w*x[k];
	                    int newy = yco + w*y[k];
	                    
	                    if(isValid(newx, newy, m, n) && grid[newx][newy] == word[w]) {
	                        continue;
	                    } else {
	                        found = false;
	                        break;
	                    }
	                }
	                if(found) {
	                    vector<int> pt;
	                    pt.push_back(i);
	                    pt.push_back(j);
	                    ans.push_back(pt);
	                    break;
	                }
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends