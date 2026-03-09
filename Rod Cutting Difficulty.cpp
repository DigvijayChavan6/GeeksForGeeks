// User function Template for C++



class Solution {
    int  getMaxPrice(int n, int N, vector<int> &price, vector<vector<int>> &dp){
        if(n == 0){
            return N * price[n];
        }
        if(dp[n][N] != -1)return dp[n][N];
        int take = INT_MIN;
        int notTake = 0 + getMaxPrice(n-1, N, price, dp);
        int lengthOfRod = n+1; 
        if(lengthOfRod <= N){ // If remaining lenght of rod is >= current rod then we take
            take = price[n] + getMaxPrice(n, N-lengthOfRod, price, dp);
        }
        
        return dp[n][N] = max(take, notTake);
    }
    
  public:
  
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return getMaxPrice(n-1, n, price, dp);
    }
};