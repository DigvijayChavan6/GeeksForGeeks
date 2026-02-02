
class Solution {
    int row, col;
    int getMaxSum(vector<vector<int>> &arr, int r, int c, vector<vector<int>> &dp){
	    if(r >= row || c >= col || c < 0)return 0;
	    if(dp[r][c] != -1)return dp[r][c];
	    int prev = getMaxSum(arr, r+1, c-1, dp) + arr[r][c];
	    int cur =  getMaxSum(arr, r+1, c, dp) + arr[r][c];
	    int next = getMaxSum(arr, r+1, c+1, dp) + arr[r][c];
	    return dp[r][c] = max(prev, max(cur, next));
    }   
  public:
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        row = mat.size();
        col = mat[0].size();
        int sum = 0;
        vector<vector<int>> dp(row, vector<int>(col, -1));
    	for(int i = 0; i < col; i++){
	    	sum = max(sum ,getMaxSum(mat, 0, i, dp));
	    }
        
        return sum;
    }
};





// User function Template for C++

class Solution {
  public:
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        if(mat.empty() || mat[0].empty())return 0;
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> dp(m, 0);
        
        for(int j = 0; j < m; j++){
            dp[j] = mat[0][j];
        }
        
        for(int i = 1; i < n; i++){
            vector<int> temp(m);
            for(int j = 0; j < m; j++){
                int up = dp[j];
                int ld = j-1 >= 0 ? dp[j-1] : INT_MIN/2;
                int rd = j+1 < m ? dp[j+1] : INT_MIN/2;
                temp[j] = max({up, ld, rd}) + mat[i][j];
            }
            dp.swap(temp);
        }
        
        int mx = INT_MIN;
        for(int j = 0; j < m; j++){
            mx = max(mx, dp[j]);
        }
        return mx;
    }
    
    // if(mat.empty() || mat[0].empty())return 0;
    //     int n = mat.size();
    //     int m = mat[0].size();
        
    //     vector<vector<int>> dp(n, vector<int>(m, 0));
        
    //     for(int j = 0; j < m; j++){
    //         dp[0][j] = mat[0][j];
    //     }
        
    //     for(int i = 1; i < n; i++){
    //         for(int j = 0; j < m; j++){
    //             int up = dp[i-1][j];
    //             int ld = j-1 >= 0 ? dp[i-1][j-1] : INT_MIN/2;
    //             int rd = j+1 < m ? dp[i-1][j+1] : INT_MIN/2;
    //             dp[i][j] = max({up, ld, rd}) + mat[i][j];
    //         }
    //     }
        
    //     int mx = INT_MIN;
    //     for(int j = 0; j < m; j++){
    //         mx = max(mx, dp[n-1][j]);
    //     }
    //     return mx;if(mat.empty() || mat[0].empty())return 0;
    //     int n = mat.size();
    //     int m = mat[0].size();
        
    //     vector<vector<int>> dp(n, vector<int>(m, 0));
        
    //     for(int j = 0; j < m; j++){
    //         dp[0][j] = mat[0][j];
    //     }
        
    //     for(int i = 1; i < n; i++){
    //         for(int j = 0; j < m; j++){
    //             int up = dp[i-1][j];
    //             int ld = j-1 >= 0 ? dp[i-1][j-1] : INT_MIN/2;
    //             int rd = j+1 < m ? dp[i-1][j+1] : INT_MIN/2;
    //             dp[i][j] = max({up, ld, rd}) + mat[i][j];
    //         }
    //     }
        
    //     int mx = INT_MIN;
    //     for(int j = 0; j < m; j++){
    //         mx = max(mx, dp[n-1][j]);
    //     }
    //     return mx;
    
    
    // int row, col;
    // int getMaxSum(vector<vector<int>> &arr, int r, int c, vector<vector<int>> &dp){
	   // if(r >= row || c >= col || c < 0)return 0;
	   // if(dp[r][c] != -1)return dp[r][c];
	   // int prev = getMaxSum(arr, r+1, c-1, dp) + arr[r][c];
	   // int cur =  getMaxSum(arr, r+1, c, dp) + arr[r][c];
	   // int next = getMaxSum(arr, r+1, c+1, dp) + arr[r][c];
	   // return dp[r][c] = max(prev, max(cur, next));
    // }   
    // int maximumPath(vector<vector<int>>& mat) {
    //     // code here
    //     row = mat.size();
    //     col = mat[0].size();
    //     int sum = 0;
    //     vector<vector<int>> dp(row, vector<int>(col, -1));
    // 	for(int i = 0; i < col; i++){
	   // 	sum = max(sum ,getMaxSum(mat, 0, i, dp));
	   // }
        
    //     return sum;
    // }
};