class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (4, 0));
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][0] = max(arr[0][1], max(arr[0][1], arr[0][2]));
        
        for(int i = 1; i < n; i++){
            for(int last = 0; last < 4; last++){
                for(int task = 0; task < 3; task++){
                    if(task != last){
                        int point  = arr[i][task] + dp[i-1][task];
                        dp[i][last] = max(dp[i][last], point);
                    }
                }
            }
        }
        
        return dp[n-1][3];
    }
};