
class Solution {
    // int getMinimumOperation(int i, int j, vector<int> &arr,
    //         vector<vector<int>> &dp){
    //     if(i == j)return 0;
    //     if(dp[i][j] != -1)return dp[i][j];
    //     int minOp = 1e9;
    //     for(int k = i; k < j; k++){
    //         int cost = getMinimumOperation(i, k, arr, dp) +
    //                     getMinimumOperation(k+1, j, arr, dp) +
    //                     arr[i-1] * arr[k] * arr[j];
    //         minOp = min(cost, minOp);
    //     }
    //     return dp[i][j] =  minOp;
    // }
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return getMinimumOperation(1, n-1, arr, dp);
        
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // for(int i = n-1; i >= 1; i--){
        //     for(int j = i+1; j < n; j++){
        //         int minOp = 1e9;
        //         for(int k = i; k < j; k++){
        //             int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
        //             minOp = min(cost, minOp);
        //         }
        //         dp[i][j] =  minOp;
        //     }
        // }
        
        for(int len = 2; len < n; len++){
            for(int i = 1; i <= n-len; i++){
                int j = i + len - 1;
                int minOp = 1e9;
                for(int k = i; k < j; k++){
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    minOp = min(cost, minOp);
                }
                dp[i][j] =  minOp;
            }
        }
        
        return dp[1][n-1];
    }
};