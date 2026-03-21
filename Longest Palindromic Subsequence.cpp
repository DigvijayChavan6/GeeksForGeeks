class Solution {
    // int getLen(int n, int m, string &s, string &k,
    // vector<vector<int>> &dp){
    //     if(n < 0 || m < 0)return 0;
        
    //     if(dp[n][m] != -1)return dp[n][m];
        
    //     int cnt = 0;
    //     if(s[n] == k[m]){
    //         cnt = 1 + getLen(n-1, m-1, s, k, dp);
    //     }
        
    //     cnt = max(cnt, getLen(n-1, m, s, k, dp));
    //     cnt = max(cnt, getLen(n, m-1, s, k, dp));
        
    //     return dp[n][m] = cnt;
    // }
  public:
    int longestPalinSubseq(string &s) {
        // code here
        string k = s;
        int n = k.size(), m = n;
        reverse(s.begin(), s.end());
        
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        vector<int> curr(n+1, 0), prev(m+1, 0);
           
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int cnt = 0;
                if(s[i-1] == k[j-1]){
                    cnt = 1 + prev[j-1];
                }
        
                cnt = max(cnt, prev[j]);
                cnt = max(cnt, curr[j-1]);
                
                curr[j] = cnt;
            }
            prev = curr;
        }
            
        return curr[m];
    }
};