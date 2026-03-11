class Solution {
    int getCount(int n, int m, string &a, string &b,
    vector<vector<int>> &dp){
        if(n < 0 || m < 0){
            return 0;
        }
        
        if(dp[n][m] != -1)return dp[n][m];
        
        int match = 0;
        int notMatch = 0;
        if(a[n] == b[m]){
            match = 1 + getCount(n-1, m-1, a, b, dp);
        }else{
            notMatch = max(getCount(n-1, m, a, b, dp), getCount(n, m-1, a, b, dp));
        }
        return dp[n][m] = max(match, notMatch);
    }
  public:
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return getCount(n-1, m-1, s1, s2, dp);
    }
};