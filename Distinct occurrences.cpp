class Solution {
public:
    int subseqCount(string s, string t) {
        int n = s.size();
        int m = t.size();
        int mod = 1e9+7;

        vector<int> curr(m+1, 0), prev(m+1, 0);

        prev[0] = 1;
        curr[0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                int match = 0;
                int notMatch = prev[j];
                if(s[i-1] == t[j-1]) match = prev[j-1];
                curr[j] = (match + notMatch) % mod;
            }
            prev = curr;
        }

        return prev[m];
    }
};