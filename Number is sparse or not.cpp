// Given a number N. The task is to check whether it is sparse or not. A number is said to be a sparse number if no two or more consecutive bits are set in the binary representation.

// Example 1:

// Input: N = 2
// Output: 1
// Explanation: Binary Representation of 2 is 10, 
// which is not having consecutive set bits. 
// So, it is sparse number.

// Example 2:

// Input: N = 3
// Output: 0
// Explanation: Binary Representation of 3 is 11, 
// which is having consecutive set bits in it. 
// So, it is not a sparse number.


// Your Task: The task is to complete the function checkSparse() that takes n as a parameter and returns 1 if the number is sparse else returns 0.


// Expected Time Complexity: O(1).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 106


class Solution{
    public:
    //Function to check if the number is sparse or not.
    bool isSparse(int n){
        return (n&(n>>1)) == 0;
        // Your code
        // int cnt=0;
        // while(n){
        //     if(n&1 == 1)cnt++;
        //     else if(cnt) cnt--;
        //     if(cnt == 2)return false;
        //     n>>=1;
        // }
        // return true;
    }
};