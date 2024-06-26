// Given a floor of dimensions 2 x n and tiles of dimensions 2 x 1, the task is to find the number of ways the floor can be tiled. A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. return the answer with modulo 109+7.

// Example 1:

// Input:
// n = 3
// Output: 3
// Explanation:
// We need 3 tiles to tile the boardof size  2 x 3. 
// We can tile in following ways:
// 1) Place all 3 tiles vertically. 
// 2) Place first tile verticallyand remaining 2 tiles horizontally.
// 3) Place first 2 tiles horizontally and remaining tiles vertically.

// Example 2:

// Input:
// n = 4
// Output:5
// Explanation:
// For a 2 x 4 board, there are 5 ways
// 1) All 4 vertical
// 2) All 4 horizontal
// 3) First 2 vertical, remaining 2 horizontal.
// 4) First 2 horizontal, remaining2 vertical.
// 5) Corner 2 vertical, middle 2 horizontal.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function numberOfWays() which takes an Integer n as input and returns the answer.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <= 105

class Solution {
  public:
    int numberOfWays(int n) {
        //code here
        int mod=1000000007;
        if(n<=1)return n;
        int a=1, b=1, ans=0;
        while(n>=2){
            ans=(a+b)%mod;
            a=b;
            b=ans;
            n--;
        }
        return ans;
    }
};