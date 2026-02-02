class Solution {
    // int getCount(int m, int n, vector<vector<int>> &dp){
    //     if(m == 0 && n == 0)return 1;
    //     if(m < 0 || n < 0)return 0;
    //     if(dp[n][m] != -1)return dp[n][m];
    //     return dp[n][m] = getCount(m-1, n, dp) + getCount(m, n-1, dp);
    // }
  public:
    int numberOfPaths(int m, int n) {
        // code here
        vector<int> dp(m, 1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = 0, prev = 0;
                up = dp[j];
                if(j-1 >= 0)prev = dp[j-1];
                dp[j] = up + prev;
            }
        }
        return dp[m-1];
        // return getCount(m-1, n-1, dp);
    }
};
