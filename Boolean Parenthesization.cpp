// User function Template for C++
class Solution {
    // int getCount(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp){
    //     if(i > j)return 0;
    //     if(i == j){
    //         if(isTrue == 1)return s[i] == 'T';
    //         return s[i] == 'F';
    //     }
        
    //     if(dp[i][j][isTrue] != -1)return dp[i][j][isTrue];
        
    //     int ways = 0;
        
    //     for(int k = i+1; k <= j-1; k += 2){
    //         int lT = getCount(i, k-1, 1, s, dp);
    //         int lF = getCount(i, k-1, 0, s, dp);
    //         int rT = getCount(k+1, j, 1, s, dp);
    //         int rF = getCount(k+1, j, 0, s, dp);
            
    //         if(s[k] == '&'){
    //             if(isTrue)ways += lT * rT;
    //             else ways += lT * rF + lF * rT + lF * rF;
    //         }else if(s[k] == '|'){
    //             if(isTrue)ways += lT * rF + lF * rT + lT * rT;
    //             else ways += lF * rF;
    //         }else{
    //             if(isTrue)ways += lF * rT + lT * rF;
    //             else ways += lT * rT + lF * rF;
    //         }
    //     }
        
    //     return dp[i][j][isTrue] = ways;
    // }
  public:
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
        for(int i = 0; i < n; i++){
            if(s[i] == 'T'){
                dp[i][i][1] = 1;
                dp[i][i][0] = 0;
            }else{
                dp[i][i][1] = 0;
                dp[i][i][0] = 1;
            }
        }
        int lT, lF, rT, rF;
        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j <= n-1; j++){
            for(int isTrue = 0; isTrue <= 1; isTrue++){
                int ways = 0;
                for(int k = i+1; k <= j-1; k++){
                    lT = dp[i][k-1][1];
                    lF = dp[i][k-1][0];
                    rT = dp[k+1][j][1];
                    rF = dp[k+1][j][0];
            
                    if(s[k] == '&'){
                        if(isTrue)ways += lT * rT;
                        else ways += lT * rF + lF * rT + lF * rF;
                    }else if(s[k] == '|'){
                        if(isTrue)ways += lT * rF + lF * rT + lT * rT;
                        else ways += lF * rF;
                    }else{
                        if(isTrue)ways += lF * rT + lT * rF;
                        else ways += lT * rT + lF * rF;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
            }
        }
        
        return dp[0][n-1][1];
    }
};