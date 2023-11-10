// Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.

// Example 1:

// Input:
// D
// Output:
// 21
// Explanation:
// D is meant for decreasing, so we choose the minimum number among all possible numbers like 21,31,54,87,etc.
// Example 2:

// Input:
// IIDDD
// Output:
// 126543
// Explanation:
// Above example is self- explanatory,
// 1 < 2 < 6 > 5 > 4 > 3
//   I - I - D - D - D
// Your Task:

// You don't need to read input or print anything. Your task is to complete the function printMinNumberForPattern() which takes the string S and returns a string containing the minimum number following the valid number.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ Length of String ≤ 8


class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans="";
        int n=S.size();
        for(int i=1;i<=n+1;i++)ans+=to_string(i);
        for(int i=0;i<n;i++){
            if(S[i]=='D'){
                int upto=1,from=i;
                while(i<n && S[i]=='D'){
                    upto++;
                    i++;
                }
                reverse(ans.begin()+from,ans.begin()+from+upto);
            }
        }
        return ans;
    }
};
