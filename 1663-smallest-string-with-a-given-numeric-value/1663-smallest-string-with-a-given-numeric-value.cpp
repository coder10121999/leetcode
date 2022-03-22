class Solution {
public:
    string getSmallestString(int n, int k) {
        int arr[n];
        for(int i=0;i<n;i++){
            arr[i]=1;
        }
        int i=n-1;
        k-=n;
        while(k>0){
            if(k<26){
                arr[i]+=k;
                break;
            }
            else{
                arr[i]+=25;
                k-=25;
                i--;
            }
        }
        
        string ans="";
        for(int i=0;i<n;i++)
            ans+='a'+(arr[i]-1);
        
        return ans;
        
    }
};