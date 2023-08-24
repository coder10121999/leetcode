//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int n = s1.length();
       int m = s2.length();
       
       int coneg = 0;
       if(s1[0] == '-') coneg++;
       if(s2[0] == '-') coneg++;
    
    //   vector<string> vec;
    //   int maxlen = 0;
       string ans = "";
    //   int outcarry = 0;
    //   int x = 0;
       vector<int> vec(n+m, 0);
       for(int i=n-1;i>=0;i--) {  // string 2 size 
          if(s1[i] == '-') continue;
            
          int num = s1[i] - '0';
        //   int carry = 0;
           
        // //   string cur = "";
        //   x = (n-1) - i;
           

           for(int j=m-1;j>=0;j--) {  // string 1 size
            if(s2[j] == '-') continue;
               // get the current product
               int val = s2[j] - '0';
               int z = num*val + vec[i+j+1];
               
               vec[i+j+1] = z%10;
               vec[i+j]+= z/10;
            //   cur = to_string(z%10) + cur;
               
               // add to total ans
            //   int len = ans.length();
            //   int a = 0;
            //   if((len-1) - x >= 0)
            //   a = ans[(len-1)-x] - '0';
            //   a += outcarry;
            //   a += z%10;
            //   if((len-1)- x>=0) {
            //       string zz = to_string(a%10);
            //       ans[(len-1) - x] = zz[0];
            //   } else {
            //       ans = to_string(a%10) + ans;
            //   }
            //   x++;
            //   outcarry = a / 10;
               
               
            //   carry = z/10;
              // cout<<z<<" "<<a<<" "<<carry<<" "<<outcarry<<"\n";
            }
            
            
            
            
            // if(carry>0) {
            
            // // cout<<carry<<"\n";
            // //   cur = to_string(carry) + cur;
            
           
            // int len = ans.length();
            // int a = 0;
            // if((len-1) - x >= 0)
            // a = ans[(len-1)-x] - '0';
            // a += outcarry;
            // a += carry;
            // if((len-1) - x>=0) { 
            //     string zz = to_string(a%10);
            //     ans[(len-1) - x] = zz[0];
            // } else {
            //     ans = to_string(a%10) + ans;
            // }
            // x++;
            // outcarry = carry / 10;
            
            // }
            
            // if(outcarry > 0) {
            // ans = to_string(outcarry) + ans;
            // outcarry = 0;
            // }
            
            //  cout<<ans<<"\n";
           
           
        //   for(int j=(n-1)-i;j>0;j--) {
        //       cur+='0';
        //   }
        //   vec.push_back(cur);
        //   maxlen = max(maxlen, (int)cur.length());
       }
    //   string ans = "";
    //   cout<<maxlen<<"\n";
    //   for(int i=0;i<vec.size();i++) {
    //       cout<<vec[i]<<"\n";
    //   }
    //   int carry = 0;
    //   for(int i=maxlen-1;i>=0;i--) {
    //         int sum = 0;
    //         int x = (maxlen-1)-i;
    //         for(int j=vec.size()-1;j>=0;j--) {
    //             string cur = vec[j];
    //             int len = cur.length();
    //             if((len-1) - x >= 0)
    //             sum += cur[(len-1) - x] - '0';
    //             else
    //             break;
    //         }
    //         sum+=carry;
    //         ans = to_string(sum%10) + ans;
    //         carry = sum/10;
    //   }
    //   if(outcarry > 0)
    //   ans = to_string(outcarry) + ans;
    //   int index = 0;
      int flen = vec.size();
      int f =0;
      if(coneg==1) ans+='-';
      for(int i=0;i<vec.size();i++) {
        //   cout<<vec[i]<<" ";
          if(vec[i] != 0) f =1 ;
          if(f) ans+=(char)(vec[i] + 48);
      }
    //   for(int i=0;i<ans.length();i++) {
    //       if(ans[i] == '0') {
    //           index = i+1;
    //           flen--;
    //       } else {
    //           break;
    //       }
    //   }
    //   string fans = flen!=0 ? ans.substr(index, flen) : "0";
      return ans;
       
       
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends