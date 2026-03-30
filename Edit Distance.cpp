
class Solution {
    int getMin(int i, int j, string &s1, string &s2,
    vector<vector<int>> &dp){
        
        if(i < 0)return j+1;
        if(j < 0)return i+1;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int ins = INT_MAX, rem = ins, rep = ins, match = ins;
        
        if(s1[i] == s2[j]){
            match = getMin(i-1, j-1, s1, s2, dp);
        }else{
            ins = 1 + getMin(i, j-1, s1, s2, dp);
            rem = 1 + getMin(i-1, j, s1, s2, dp);
            rep = 1 + getMin(i-1, j-1, s1, s2, dp);
        }
        
        return dp[i][j] = min(match, min(ins, min(rem, rep)));
    }
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return getMin(n-1, m-1, s1, s2, dp);
    }
};