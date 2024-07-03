// A frog jumps either 1, 2, or 3 steps to go to the top. In how many ways can it reach the top of Nth step. As the answer will be large find the answer modulo 1000000007.

// Example 1:

// Input:
// N = 1
// Output: 1

// Example 2:

// Input:
// N = 4
// Output: 7
// Explanation:Below are the 7 ways to reach
// 4
// 1 step + 1 step + 1 step + 1 step
// 1 step + 2 step + 1 step
// 2 step + 1 step + 1 step
// 1 step + 1 step + 2 step
// 2 step + 2 step
// 3 step + 1 step
// 1 step + 3 step

// Your Task:
// Your task is to complete the function countWays() which takes 1 argument(N) and returns the answer%(10^9 + 7).

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 10

class Solution{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n){
        if(n<=2)return n;
        vector<long long> v(n+1, 0);
        v[1]=1; v[2]=2; v[3]=4;
        for(int i=4;i<=n;i++){
            v[i]=(v[i-3]+v[i-2]+v[i-1])%1000000007;
        }
        return v[n];
    }
};