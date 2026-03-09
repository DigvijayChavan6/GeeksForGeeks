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






// User function Template for C++



class Solution {
    // int  getMaxPrice(int n, int N, vector<int> &price, vector<vector<int>> &dp){
    //     if(n == 0){
    //         return N * price[n];
    //     }
    //     if(dp[n][N] != -1)return dp[n][N];
    //     int take = INT_MIN;
    //     int notTake = 0 + getMaxPrice(n-1, N, price, dp);
    //     int lengthOfRod = n+1; 
    //     if(lengthOfRod <= N){ // If remaining lenght of rod is >= current rod then we take
    //         take = price[n] + getMaxPrice(n, N-lengthOfRod, price, dp);
    //     }
        
    //     return dp[n][N] = max(take, notTake);
    // }
    
  public:
  
    int cutRod(vector<int> &price) {
        // code here
        // int n = price.size();
        // vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        // for(int N = 0; N <= n; N++){
        //     dp[0][N] = N * price[0];
        // }
        
        // for(int i = 1; i < n; i++){
        //     for(int N = 0; N <= n; N++){
        //         int take = INT_MIN;
        //         int notTake = 0 + dp[i-1][N];
        //         int lengthOfRod = i+1; 
        //         if(lengthOfRod <= N){ // If remaining lenght of rod is >= current rod then we take
        //             take = price[i] + dp[i][N-lengthOfRod];
        //         }
        //         dp[i][N] = max(take, notTake);
        //     }
        // }
        
        // return dp[n-1][n];
        
        
        int n = price.size();
        vector<int> curr(n+1, 0), prev(n+1, 0);
        
        for(int N = 0; N <= n; N++){
            prev[N] = N * price[0];
        }
        
        for(int i = 1; i < n; i++){
            for(int N = 0; N <= n; N++){
                int take = INT_MIN;
                int notTake = 0 + prev[N];
                int lengthOfRod = i+1; 
                if(lengthOfRod <= N){ // If remaining lenght of rod is >= current rod then we take
                    take = price[i] + curr[N-lengthOfRod];
                }
                curr[N] = max(take, notTake);
            }
            prev = curr;
        }
        
        return prev[n];
        
    }
};