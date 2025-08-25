// Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.

// Note: Each element must be in exactly one subset.

// Examples:

// Input: arr = [1, 5, 11, 5]
// Output: true
// Explanation: The two parts are [1, 5, 5] and [11].
// Input: arr = [1, 3, 5]
// Output: false
// Explanation: This array can never be partitioned into two such parts.
// Constraints:
// 1 ≤ arr.size ≤ 100
// 1 ≤ arr[i] ≤ 200

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = 0;
        for(int val : arr)sum += val;
        if(sum%2 == 1)return false;
    
        sum /= 2;
        int n = arr.size();
        vector<bool> dp(sum+1, false);
        
        dp[0] = true;
        
        for(int i = 0; i < n; i++){
            for(int j = sum; j >= arr[i]; j--){
                dp[j] = dp[j] || dp[j-arr[i]];
            }
        }
        
        return dp[sum];
    }
    
    //     vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
    //     for(int i = 0; i < n; i++)dp[i][0] = true;
        
    //     for(int i = 1; i <= n; i++){
    //         for(int j = 1; j <= sum; j++){
    //             bool notPick = dp[i-1][j];
    //             bool pick = false;
    //             if(j >= arr[i-1]){
    //                 pick = dp[i-1][j-arr[i-1]];
    //             }
    //             dp[i][j] = notPick || pick;
    //         }
    //     }
        
    //     return dp[n][sum];
    // }
};