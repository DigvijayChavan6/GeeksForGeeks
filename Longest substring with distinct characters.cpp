// Given a string s, find the length of the longest substring with all distinct characters. 

// Examples:

// Input: s = "geeksforgeeks"
// Output: 7
// Explanation: "eksforg" is the longest substring with all distinct characters.
// Input: s = "aaa"
// Output: 1
// Explanation: "a" is the longest substring with all distinct characters.
// Input: s = "abcdefabcbb"
// Output: 6
// Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.
// Constraints:
// 1<= s.size()<=3*104
// All the characters are in lowercase.

class Solution {
  public:
    int longestUniqueSubstr(string &S) {
        // code here
        int cnt=0, i = 0;
        unordered_map<char, int> mp;
        
        for(int j = 0; j < S.size(); ++j){
            while(mp.find(S[j]) != mp.end()){
                mp.erase(S[i++]);
            }
            mp[S[j]]++;
            cnt = max(cnt, j-i+1);
        }
        
        return cnt;
    }
};