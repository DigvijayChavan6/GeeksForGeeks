// Given two strings s1 and s2. Modify both the strings such that all the common characters of s1 and s2 are to be removed and the uncommon characters of s1 and s2 are to be concatenated.
// Note: If all characters are removed print -1.

// Example 1:

// Input:
// s1 = aacdb
// s2 = gafd
// Output: cbgf
// Explanation: The common characters of s1
// and s2 are: a, d. The uncommon characters
// of s1 and s2 are c, b, g and f. Thus the
// modified string with uncommon characters
// concatenated is cbgf.

// Example 2:

// Input:
// s1 = abcs
// s2 = cxzca
// Output: bsxz
// Explanation: The common characters of s1
// and s2 are: a,c. The uncommon characters
// of s1 and s2 are b,s,x and z. Thus the
// modified string with uncommon characters
// concatenated is bsxz.

// Your Task:
// The task is to complete the function concatenatedString() which removes the common characters, concatenates, and returns the string. If all characters are removed then return -1.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Number of distinct characters).
// Note: N = |Length of Strings|

// Constraints: 
// 1 <= |Length of Strings| <= 104


class Solution{
    public:
    void concate(string &answer, string s, map<char, int> &mp){
        for(char c : s){
            if(mp[c] != 2){
                answer+=c;
            }
        }
    }
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) { 
        // Your code here
        map<char, int> mp;
        int n=s1.size(), m=s2.size();
        string answer="";
        for(int i=0;i<n;i++){
            mp[s1[i]]=1;
        }
        for(int i=0;i<m;i++){
            if(mp[s2[i]] == 1){
                mp[s2[i]]=2;
            }
        }
        concate(answer, s1, mp);
        concate(answer, s2, mp);
        if(answer == "")return "-1";
        return answer;
    }
};