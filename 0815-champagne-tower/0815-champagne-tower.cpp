class Solution {
public:

    double champagneTower(int poured, int query_row, int query_glass) {
        
        double dp[101][101];
        memset(dp, 0.0, sizeof(dp));

        dp[0][0] = poured;
        for(int i=0;i<100;i++) {
            for(int j=0;j<=i;j++) {
                if(dp[i][j] <= 1) continue;
                else {
                    double left = dp[i][j]-1;
                    dp[i][j] = 1;
                    dp[i+1][j]+=(left/2.0);
                    dp[i+1][j+1]+=(left/2.0);
                }
            }
        }

        return dp[query_row][query_glass];
        
    }
};