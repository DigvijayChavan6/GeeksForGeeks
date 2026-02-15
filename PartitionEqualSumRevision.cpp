class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int total = 0;
        for(int val : arr){
            total += val;
        }
        
        if(total % 2 == 1)return false;
        
        int n = arr.size();
        int k = total / 2;
        
        vector<bool> dp(k+1, false);
        
        dp[0] = true;
        
        for(int i = 0; i < n; i++){
            for(int sum = k; sum >= arr[i]; sum--){
                bool pick = dp[sum-arr[i]];
                bool noPick = dp[sum];
                dp[sum] = pick || noPick;
            }
        }
        
        return dp[k];
    }
};