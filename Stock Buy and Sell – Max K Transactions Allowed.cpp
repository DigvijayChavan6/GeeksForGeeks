class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(k+1, 0));

        for(int i = n-1; i >= 0; i--){
            vector<vector<int>> dp(2, vector<int>(k+1, 0));
            for(int canBuy = 0; canBuy <= 1; canBuy++){
                for(int tranCount = k-1; tranCount >= 0; tranCount--){
                    int profit = 0;
                    int consider = 0;
                    int notConsider = 0;
                    if(canBuy == 1){
                        consider = -prices[i] + prev[0][tranCount];
                        notConsider = prev[1][tranCount];
                    }else{
                        consider = prices[i] + prev[1][tranCount+1];
                        notConsider = prev[0][tranCount];
                    }
                    profit = max(consider, notConsider);
                    dp[canBuy][tranCount] = profit;
                }
            }
            prev = dp;
        }

        return prev[1][0];
    }
};