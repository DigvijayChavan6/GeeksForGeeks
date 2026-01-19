// User function Template for C++
class Solution {
    // int getPaths(int m, int n, vector<vector<int>> &dp){
    //     if(m < 0 || n < 0)return 0;
    //     if(m == 0 && n == 0){
    //         return 1;
    //     }
    //     if(dp[m][n] != -1)return dp[m][n];
    //     return dp[m][n] = getPaths(m-1, n, dp) + getPaths(m, n-1, dp);
    // }
  public:
    int numberOfPaths(int m, int n) {
        // code here
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return getPaths(m-1, n-1, dp);
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = 1;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i-1 >= 0)dp[i][j] += dp[i-1][j];
                if(j-1 >= 0)dp[i][j] += dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};