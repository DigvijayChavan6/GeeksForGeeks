// Given an array a[ ] of n integers, find the Length of the Longest Strictly Increasing Subsequence.

// A sequence of numbers is called "strictly increasing" when each term in the sequence is smaller than the term that comes after it.

// Example 1:

// Input: n = 6, a[ ] = {5,8,3,7,9,1}
// Output: 3
// Explanation: There are more than one LIS in this array.  
// One such Longest increasing subsequence is {5,7,9}.
// Example 2:

// Input: n = 16, a[ ] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
// Output: 6
// Explanation: There are more than one LIS in this array. 
// One such Longest increasing subsequence is {0,2,6,9,13,15}.
// Your Task:
// You do not need to read input or print anything. Complete the function longestSubsequence() which takes the given array and its size as input parameters and returns the length of the longest increasing subsequence.

// Expected Time Complexity : O( n*log(n) )
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n ≤ 104
// 0 ≤ a[i] ≤ 106

class Solution{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]){
       // your code here
       int mx = 0;
       vector<int> dp(n, 1);
       for(int i=1; i<n; ++i){
           for(int j=0; j<i; ++j){
               if(a[i]>a[j] && dp[i]<dp[j]+1){
                   dp[i] = dp[j] + 1;
               }
           }
       }
       for(int val : dp){
           mx = max(mx, val);
       }
       return mx;
    }
};
