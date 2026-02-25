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



  public:
    int minCoins(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        
        for(int s = 0; s <= sum; s++){
            if(s%coins[0] == 0)dp[0][s] = s/coins[0];
            else dp[0][s] = 1e9;
        }
        
        for(int i = 1; i < n; i++){
            for(int s = 0; s <= sum; s++){
                int take = 1e9;
                int notTake = dp[i-1][s];
                if(coins[i] <= s){
                    take = 1 + dp[i][s-coins[i]];
                }
        
                dp[i][s] = min(take, notTake);
            }
        }
        
        int cnt = dp[n-1][sum];
        if(cnt == 1e9)return -1;
    
        return cnt;
    }
};