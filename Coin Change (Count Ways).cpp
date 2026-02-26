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



  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        
        for(int s = 0; s <= sum; s++){
            if(s%coins[0] == 0)dp[0][s] = 1;
            else dp[0][s] = 0;
        }
        
        for(int i = 1; i < n; i++){
            for(int s = 0; s <= sum; s++){
                int take = 0;
                int notTake = dp[i-1][s];
                if(coins[i] <= s){
                    take = dp[i][s-coins[i]];
                }
                dp[i][s] = take + notTake;
            }
        }
        return dp[n-1][sum];
    }
};

  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<int> dp(sum+1, 0);
        
        for(int s = 0; s <= sum; s++){
            if(s%coins[0] == 0)dp[s] = 1;
            else dp[s] = 0;
        }
        
        for(int i = 1; i < n; i++){
            for(int s = 0; s <= sum; s++){
                int take = 0;
                int notTake = dp[s];
                if(coins[i] <= s){
                    take = dp[s-coins[i]];
                }
                dp[s] = take + notTake;
            }
        }
        return dp[sum];
    }
};