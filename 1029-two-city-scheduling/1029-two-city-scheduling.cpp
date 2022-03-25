class Solution {
public:
    int dp[105][105];
    int comb(int i,vector<vector<int>>& costs,int coa,int cob,int n){
        
       // cout<<i<<" "<<coa<<" "<<dp[i][coa]<<"\n";
        if(dp[i][coa]!=-1)
            return dp[i][coa];

        if(i==n)
            return 0;
        
        
        
        int a=0;
        int b=0;
        if(coa>=(n/2)){
            a=INT_MAX;
            b=costs[i][1]+comb(i+1,costs,coa,cob+1,n);
        }
        else if(cob>=(n/2)){
            a=costs[i][0]+comb(i+1,costs,coa+1,cob,n);
            b=INT_MAX;
        }
        else{
            a=costs[i][0]+comb(i+1,costs,coa+1,cob,n);
            b=costs[i][1]+comb(i+1,costs,coa,cob+1,n);
        }
        dp[i][coa]=min(a,b);
        return min(a,b);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n=costs.size();
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n+1;j++)
                dp[i][j]=-1;
        }
        int ans=comb(0,costs,0,0,n);
        return ans;
        
    }
};