class Solution {
  public:
    
    int minPathSum(vector<vector<int>>& tri) {
        // Code here
        int n = tri.size();
        
        vector<int> dp(n, 0);
        
        for(int j = 0; j < n; j++){
            dp[j] = tri[n-1][j];
        }
        
        for(int i = n-2; i >= 0; i--){
            vector<int> temp(n);
            for(int j = i; j >= 0; j--){
                int up = tri[i][j] + dp[j];
                int dnl = tri[i][j] + dp[j+1];
                temp[j] = min(up, dnl);
            }
            dp = temp;
        }
        
        return dp[0];
    }
  
    // int minPathSum(vector<vector<int>>& tri) {
    //     // Code here
    //     int n = tri.size();
    //     vector<vector<int>> dp;
    //     for(auto v : tri){
    //         dp.push_back(vector<int>(v.size(), -1));
    //     }
    //     for(int j = 0; j < n; j++){
    //         dp[n-1][j] = tri[n-1][j];
    //     }
        
    //     for(int i = n-2; i >= 0; i--){
    //         for(int j = i; j >= 0; j--){
    //             int up = tri[i][j] + dp[i+1][j];
    //             int dnl = tri[i][j] + dp[i+1][j+1];
    //             dp[i][j] = min(up, dnl);
    //         }
    //     }
        
    //     return dp[0][0];
    // }
    
    
    
    // int getSum(int row, int col, int n, vector<vector<int>> &tri,
    //     vector<vector<int>> &dp){
    //     if(row >= n || col >= tri[row].size())return 0;
    //     if(dp[row][col] != -1 )return dp[row][col];
    //     int below = getSum(row + 1, col, n, tri, dp);
    //     int next = getSum(row + 1, col + 1, n, tri, dp);
    //     return dp[row][col] = min(below, next) + tri[row][col];
    // }
    
    // int minPathSum(vector<vector<int>>& triangle) {
    //     // Code here
    //     int n = triangle.size();
    //     vector<vector<int>> dp;
    //     for(auto v : triangle){
    //         dp.push_back(vector<int>(v.size(), -1));
    //     }
    //     return getSum(0, 0, n, triangle, dp);
    // }
};