//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int row[n];
        int col[n];
        for(int i=0;i<n;i++) {
            row[i] =0;
            col[i] =0;
        }
        for(int i=0;i<n;i++) {
            int sum = 0;
            for(int j=0;j<n;j++) {
                sum += matrix[i][j];
                col[j] += matrix[i][j];
            }
            row[i] = sum;
        }
        int maxv = 0;
        for(int i=0;i<n;i++) {
            //cout<<row[i]<<" ";
            maxv = max(maxv, row[i]);
            maxv = max(maxv, col[i]);
        }
        
        // cout<<"\n";
        // for(int i=0;i<n;i++) {
        //     cout<<col[i]<<" ";
        // }
        // cout<<"\n";
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans += maxv - row[i];
            ans += maxv - col[i];
        }
        return ans/2;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends