//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    bool isValid(int x, int y, int n, int m) {
        return x>=0 && x<n && y>=0 && y<m;
    }

    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                
                if(matrix[i][j] == 1) {
                int co = 0;
                for(int k= 0;k<8;k++) {
                    int xc = i+x[k];
                    int yc = j+y[k];
                    if(isValid(xc, yc, n, m) && matrix[xc][yc] == 0) {
                        co++;
                    }
                }
                //cout<<co<<"\n";
                if(co>0 && co%2==0)
                ans++;
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
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends