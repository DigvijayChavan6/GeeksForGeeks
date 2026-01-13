// User function template for C++
class Solution {
    int getSum(vector<int> &arr, int ind, vector<int> &dp){
        if(ind < 0)return 0;
        if(dp[ind] != -1)return dp[ind];
        int take = getSum(arr, ind-2, dp) + arr[ind];
        int skip = getSum(arr, ind-1, dp);
        return dp[ind] = max(take, skip);
    }
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr, int n) {
        // code here
        vector<int> dp(n+1, -1);
        return getSum(arr, n-1, dp);
    }
};