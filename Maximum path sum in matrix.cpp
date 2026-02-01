
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