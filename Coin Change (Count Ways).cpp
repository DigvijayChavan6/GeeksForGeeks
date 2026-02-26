class Solution {
    
    int getCount(int n, int sum, vector<int> &coins,
    vector<vector<int>> &dp){
        if(n == 0){
            if(sum%coins[0] == 0)return 1;
            else return 0;
        }
        
        if(dp[n][sum] != -1)return dp[n][sum];
        
        int take = 0;
        int notTake = getCount(n-1, sum, coins, dp);
        if(coins[n] <= sum){
            take = getCount(n, sum-coins[n], coins, dp);
        }
        return dp[n][sum] = take + notTake;
    }
    
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return getCount(n-1, sum, coins, dp);
    }
};