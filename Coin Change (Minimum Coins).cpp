class Solution {
    
    int getCount(int n, int sum, vector<int> &coins,
    vector<vector<int>> &dp){
        
        if(n == 0){
            if(sum%coins[0] == 0)return sum/coins[0];
            else return 1e9;
        }
        
        if(dp[n][sum] != -1)return dp[n][sum];
        
        int take = 1e9;
        int notTake = getCount(n-1, sum, coins, dp);
        if(coins[n] <= sum){
            take = 1 + getCount(n, sum-coins[n], coins, dp);
        }
        
        return dp[n][sum] = min(take, notTake);
    }
    
  public:
    int minCoins(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        int cnt = getCount(n-1, sum, coins, dp);
        if(cnt == 1e9)return -1;
    
        return cnt;
    }
};