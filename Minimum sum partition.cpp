class Solution {

  public:
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int total =  0;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            total += arr[i];
        }
        
        int dif = INT_MAX;
        vector<int> dp(total+1, false);
        dp[0] = true;
        
        for(int i = 0; i < n; i++){
            for(int s = total; s >= arr[i]; s--){
                bool noPick = dp[s];
                bool pick = dp[s-arr[i]];
                dp[s] = noPick || pick;
            }
        }
        
        for(int i = 0; i <= total; i++){
            if(dp[i] == true){
                dif = min(dif, abs(total - (2 * i)));
            }
        }
        
        return dif;
    }
};