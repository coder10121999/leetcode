//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            // int BITS = 0;
            // int z =n;
            // while(z!=0) {
            //     BITS++;
            //     z/=2;
            // }
            // cout<<BITS<<"\n";
            int maxv = (1<<16) - 1;
            d=(d-1)%16;
            d++;
            vector<int> vec;
            int first = (maxv & n<<d) | n>>(16-d);
            int second = n>>d | (n<<(16-d) & maxv);
            
            vec.push_back(first);
            vec.push_back(second);
            return vec;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends