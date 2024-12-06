Given an array of positive integers, arr[] and a value, target, determine if there is a subset of the given set with sum equal to given target. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2, target = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 4*104


class Solution {
    
    // bool isPresent(vector<int> &arr, int n, int target, vector<vector<int>> &memo){
    //     if(target == 0)return true;
    //     if(n < 0)return false;
    //     if(memo[n][target] != -1){
    //         return memo[n][target];
    //     }
    //     bool exclude = isPresent(arr, n-1, target, memo);
    //     bool include = (target-arr[n] >= 0) ? isPresent(arr, n-1, target-arr[n], memo) : false;
        
    //     memo[n][target] = exclude || include;
        
    //     return memo[n][target];
    // }
    
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        // vector<vector<int>> memo(arr.size()+1, vector<int>(target+1, -1));
        // return isPresent(arr, arr.size()-1, target, memo);
        
        vector<bool> dp(target+1, false);
        dp[0] = true;
        
        for(int value : arr){
            for(int val = target; val >= value; --val){
                dp[val] = dp[val] || dp[val-value];
            }
        }
        
        return dp[target];
    }
};