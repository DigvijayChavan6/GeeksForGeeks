// User function template for C++
class Solution {
    // bool isMatching(int i, int j, string &wild, string &pattern,
    // vector<vector<int>> &dp){
        
    //     if(i <= 0 && j <= 0)return true;
    //     if(i <= 0 && j >= 1)return false;
    //     if(i >= 1 && j <= 0){
    //         for(int k = 1; k <= i; k++){
    //             if(wild[k-1] != '*')return false;
    //         }
    //         return true;
    //     }
        
    //     if(dp[i][j] != -1)return dp[i][j];
        
    //     if(wild[i-1] == pattern[j-1] || wild[i-1] == '?'){
    //         return dp[i][j] = isMatching(i-1, j-1, wild, pattern, dp);
    //     }
    //     if(wild[i-1] == '*'){
    //         return dp[i][j] = isMatching(i-1, j, wild, pattern, dp) || 
    //                 isMatching(i, j-1, wild, pattern, dp); 
    //     }
    //     return dp[i][j] = 0;
    // }
  public:
    bool match(string wild, string pattern) {
        // code here
        int n = wild.size(), m = pattern.size();
        vector<bool> prev(m+1, false);
        prev[0] = true;
        
        for(int i = 1; i <= n; i++){
            vector<bool> curr(m+1, false);
            curr[0] = prev[0] && wild[i-1] == '*';
            for(int j = 1; j <= m; j++){
                if(wild[i-1] == pattern[j-1] || wild[i-1] == '?'){
                    curr[j] = prev[j-1];
                }
                else if(wild[i-1] == '*'){
                    curr[j] = prev[j] || curr[j-1]; 
                }else{
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        
        return prev[m];
    }
};














