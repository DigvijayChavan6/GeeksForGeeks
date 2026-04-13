class Solution {
    // int getLen(int i, int prev, bool flag, vector<int> &nums){
    //     if(i < 0)return 0;
    //     int len = 0;
        
    //     if(flag == 1 && nums[i] > prev){
    //         int inc = getLen(i-1, nums[i], flag, nums);
    //         int dec = getLen(i-1, nums[i], !flag, nums);
    //         len = 1 + max(inc, dec);
    //     }
    //     if(flag == 0 && nums[i] < prev){
    //         len = 1 + getLen(i-1, nums[i], flag, nums);
    //     }
        
    //     return len;
    // }
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        
        vector<int> dp1(n, 1), dp2(n, 1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp1[j] + 1 > dp1[i]){
                    dp1[i] = 1 + dp1[j];
                }
            }
        }
        
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j > i; j--){
                if(nums[i] > nums[j] && dp2[j] + 1 > dp2[i]){
                    dp2[i] = 1 + dp2[j];
                }
            }
        }
        
        int maxLen = 0;
        
        for(int i = 0; i < n; i++){
            if(dp1[i] != 1 && dp2[i] != 1){
                maxLen = max(maxLen, dp1[i] + dp2[i] - 1);
            }
        }
        
        return maxLen;
        //return max(getLen(n-1, -1, false, nums), getLen(n-1, -1, true, nums));
    }
};