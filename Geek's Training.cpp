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











class Solution {
    // int getMax(vector<vector<int>> &arr, int day, int last,
    // vector<vector<int>> &dp){
    //     int mx = 0;
    //     if(day == 0){
    //         for(int i = 0; i < 3; i++){
    //             mx = max(arr[day][i], mx);
    //         }
    //         return mx;
    //     }
    //     if(dp[day][last] != -1)return dp[day][last];
    //     for(int i = 0; i < 3; i++){
    //         if(i != last){
    //             int point = arr[day][i] + getMax(arr, day-1, i, dp);
    //             mx = max(mx, point);
    //         }
    //     }
    //     return dp[day][last] = mx;
    // }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        
        int n = arr.size();
        vector<int> dp(4, 0);
        dp[0] = max(arr[0][1], arr[0][2]);
        dp[1] = max(arr[0][0], arr[0][2]);
        dp[2] = max(arr[0][0], arr[0][1]);
        dp[3] = max(arr[0][1], max(arr[0][1], arr[0][2]));
        for(int  i = 1; i < n; i++){
            vector<int> temp(4, 0);
            for(int last = 0; last < 4; last++){
                for(int task = 0; task < 3; task++){
                    if(task != last){
                        int point  = arr[i][task] + dp[task];
                        temp[last] = max(temp[last], point);
                    }
                }
            }
            dp = temp;
        }
        
        return dp[3];
        
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int> (4, -1));
        // return getMax(arr, n-1, 3, dp);
        
        // // Code here
        // int n = arr.size();
        // vector<vector<int>> dp(n, vector<int> (4, 0));
        // dp[0][0] = max(arr[0][1], arr[0][2]);
        // dp[0][1] = max(arr[0][0], arr[0][2]);
        // dp[0][2] = max(arr[0][0], arr[0][1]);
        // dp[0][3] = max(arr[0][1], max(arr[0][1], arr[0][2]));
        
        // for(int i = 1; i < n; i++){
        //     for(int last = 0; last < 4; last++){
        //         for(int task = 0; task < 3; task++){
        //             if(task != last){
        //                 int point  = arr[i][task] + dp[i-1][task];
        //                 dp[i][last] = max(dp[i][last], point);
        //             }
        //         }
        //     }
        // }
        
        // return dp[n-1][3];
    }
};