// Given an array of positive integers arr. Find the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence. 

// Examples:

// Input: arr[] = [1, 101, 2, 3, 100]
// Output: 106
// Explanation: The maximum sum of a increasing sequence is obtained from [1, 2, 3, 100].
// Input: arr[] = [4, 1, 2, 3]
// Output: 6
// Explanation: The maximum sum of a increasing sequence is obtained from {1, 2, 3}.
// Input: arr[] = [4, 1, 2, 4]
// Output: 7
// Explanation: The maximum sum of a increasing sequence is obtained from {1, 2, 4}.
// Constraints:
// 1  ≤  arr.size()  ≤  103
// 1  ≤  arr[i]  ≤  105

class Solution {
    int n;
    int dp[1001][1001];
    int getSum(vector<int> &arr, int i, int prev){
        if(i >= n){
            return 0;
        }
        if(dp[i][prev+1] != -1)return dp[i][prev+1];
        int skip = 0, take = 0;
        if(prev == -1 || arr[i] > arr[prev]){
            take = getSum(arr, i+1, i) + arr[i];
        }
        skip = getSum(arr, i+1, prev);
        
        return dp[i][prev+1] = max(take, skip);
    }
  
  public:
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return getSum(arr, 0, -1);
    }
};


int maxSumIS(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        vector<int> dp(arr);
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[i] > arr[j] && dp[i] < arr[i]+dp[j]){
                    dp[i] = arr[i]+dp[j];
                    sum = max(sum, dp[i]);
                }
            }
            sum = max(sum, arr[i]);
        }
        
        return sum;
}