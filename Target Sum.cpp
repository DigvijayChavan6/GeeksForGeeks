class Solution {
    // long long getSumCount(int n, long long sum, vector<int> &arr,
    // vector<vector<long long>> &dp){
        
    //     if(n == 0){
    //         if(sum == 0 && arr[0] == sum)return 2;
    //         if(sum == 0 || arr[0] == sum)return 1;
    //         return 0;
    //     }
        
    //     if(dp[n][sum] != 1e9)return dp[n][sum];
        
    //     long long pick = 0;
    //     long long notPick = getSumCount(n-1, sum, arr, dp);
    //     if(arr[n] <= sum){
    //         pick = getSumCount(n-1, sum-arr[n], arr, dp);
    //     }
    //     return dp[n][sum] = (pick + notPick) % 1000000007;
    // }
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        long long total = 0;
        for(int val : A)total += val;
        
        if((target + total) % 2 == 1)return 0;
        if(total < abs(target))return 0;
        
        long long sum = (target + total) / 2;
        
        vector<vector<long long>> dp(n, vector<long long>(sum+1, 0));
        
        for(int i = 0; i <= sum; i++){
            if(i == 0 && A[0] == i)dp[0][i] = 2;
            if(i == 0 || A[0] == i)dp[0][i] = 1;
            else dp[0][i] = 0;
        }    
    
    
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= sum; j++){
                long long pick = 0;
                long long notPick = dp[i-1][j];
                if(A[i] <= j){
                    pick = dp[i-1][j-A[i]];
                }
                dp[i][j] = (pick + notPick) % 1000000007;
            }
        }
        
        return dp[n-1][sum];
        //return getSumCount(n-1, sum, A, dp);
    }
};







class Solution {
    // long long getSumCount(int n, long long sum, vector<int> &arr,
    // vector<vector<long long>> &dp){
        
    //     if(n == 0){
    //         if(sum == 0 && arr[0] == sum)return 2;
    //         if(sum == 0 || arr[0] == sum)return 1;
    //         return 0;
    //     }
        
    //     if(dp[n][sum] != 1e9)return dp[n][sum];
        
    //     long long pick = 0;
    //     long long notPick = getSumCount(n-1, sum, arr, dp);
    //     if(arr[n] <= sum){
    //         pick = getSumCount(n-1, sum-arr[n], arr, dp);
    //     }
    //     return dp[n][sum] = (pick + notPick) % 1000000007;
    // }
  public:
    long long findTargetSumWays(int n, vector<int>& A, int target) {
        // Your code here
        long long total = 0;
        for(int val : A)total += val;
        
        if((target + total) % 2 == 1)return 0;
        if(total < abs(target))return 0;
        
        long long sum = (target + total) / 2;
        
        vector<long long> dp(sum+1, 0);
        
        for(int i = 0; i <= sum; i++){
            if(i == 0 && A[0] == i)dp[i] = 2;
            if(i == 0 || A[0] == i)dp[i] = 1;
            else dp[i] = 0;
        }    
    
    
        for(int i = 1; i < n; i++){
            for(int j = sum; j >= 0; j--){
                long long pick = 0;
                long long notPick = dp[j];
                if(A[i] <= j){
                    pick = dp[j-A[i]];
                }
                dp[j] = (pick + notPick) % 1000000007;
            }
        }
        
        return dp[sum];
        //return getSumCount(n-1, sum, A, dp);
    }
};
