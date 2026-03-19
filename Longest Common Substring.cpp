
class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // your code here
        
        int n = s1.size();
        int m = s2.size();
        int mx = 0;
        vector<int> prev(m+1, 0);
        
        for(int i = 1; i <= n; i++){
            vector<int> dp(m+1, 0);
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[j] = 1 + prev[j-1];
                    mx = max(dp[j], mx);
                }
            }
            prev = dp;
        }
    
        return mx;
        
        
        
        // int n = s1.size();
        // int m = s2.size();
        // int mx = 0;
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         if(s1[i-1] == s2[j-1]){
        //             dp[i][j] = 1 + dp[i-1][j-1];
        //             mx = max(dp[i][j], mx);
        //         }
        //     }
        // }
    
        // return mx;
    }
};