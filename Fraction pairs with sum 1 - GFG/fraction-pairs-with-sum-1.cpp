//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int gcd(int a, int b) {
        if(b==0)
            return a;
        
        return gcd(b, a%b);
    }

    int countFractions(int n, int numerator[], int denominator[])
    {
        // for(int i=0;i<n;i++) {
        //     int div = gcd(numerator[i], denominator[i]);
        //     numerator[i] /= div;
        //     denominator[i] /= div;
        // }
        
        map<pair<int,int>, int> mp;
        
        int counthalf = 0;
        for(int i=0;i<n;i++) {
            int div = gcd(numerator[i], denominator[i]);
            numerator[i] /= div;
            denominator[i] /= div;
            int num = numerator[i];
            int den = denominator[i];
            if(den == 2 && num == 1) {
                counthalf++;
                continue;
            }
            mp[{den, num}]++;
        }
        
        
        // sort(vec.begin(), vec.end(), comp);
        int ans = 0;
        for(int i=0;i<n;i++) {
            
            int num = numerator[i];
            int den = denominator[i];
            
            int top = den - num;
            int bot = den;
            int val = mp[{bot, top}];
            ans += val;
        }
        ans /= 2;
        if(counthalf >= 1) 
        ans += (counthalf * (counthalf - 1))/2;
        
        
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends