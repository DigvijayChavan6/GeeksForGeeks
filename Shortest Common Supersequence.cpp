


class Solution {
    // int getLen(string &a, string &b, int n, int m,
    // vector<vector<int>> &dp){
    //     if(n <= 0 || m <= 0)return 0;
        
    //     int cnt = 0;
        
    //     if(dp[n][m] != -1){
    //         return dp[n][m];
    //     }
        
    //     if(a[n-1] == b[m-1]){
    //         cnt = 1 + getLen(a, b, n-1, m-1, dp);
    //     }else{
    //         cnt = max(cnt, getLen(a, b, n-1, m, dp));
    //         cnt = max(cnt, getLen(a, b, n, m-1, dp));
    //     }
        
    //     return dp[n][m] = cnt;
    // }
  public:
    int minSuperSeq(string &a, string &b) {
        // code here
        int n = a.size();
        int m = b.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> curr(m+1, 0), prev(m+1, 0);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int cnt = 0;
                if(a[i-1] == b[j-1]){
                    cnt = 1 + prev[j-1];
                }else{
                    cnt = max(cnt, prev[j]);
                    cnt = max(cnt, curr[j-1]);
                }
                
                curr[j] = cnt;
            }
            prev = curr;
        }
        
       // int lcsLen = getLen(s1, s2, n, m, dp);
        
        return n + m - curr[m];
    }
};