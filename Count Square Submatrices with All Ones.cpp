// User function Template for C++

class Solution {
  public:
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        // code here
        int cnt = 0;

        vector<vector<int>> dp = matrix;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if( matrix[i][j] == 1){
                    if(i-1 >= 0 && j-1 >= 0)
                        dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                    else{
                        dp[i][j] = 1;
                    }
                    cnt += dp[i][j];
                }
            }
        }
        return cnt;
    }
};