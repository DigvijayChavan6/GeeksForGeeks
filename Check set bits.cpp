// Given a number N. You have to check whether every bit in the binary representation of the given number is set or not.

// Example 1:

// Input:
// N = 7
// Output:
// 1
// Explanation:
// Binary for 7 is 111 all the
// bits are set so output is 1

// Example 2:

// Input:
// N = 8
// Output:
// 0
// Explanation:
// Binary for 8 is 1000 all the
// bits are not set so output is 0.


// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isBitSet() which takes an integer N as input parameters and returns 1 if all the bits in N's binary representation is set or return 0 otherwise.

// Expected Time Complexity: O(1)
// Expected Space Complexity: O(1)

// Constraints:
// 0<=N<=100000

class Solution{
public:
    int isBitSet(int N){
        // code here 
        if(!N)return N;
        return ((N+1)&N) == 0;
        // ++N;
        // int x=1;
        // int i=0;
        // while(x<N){
        //     x=1<<i;
        //     i++;
        // }
        // return x==N;
    }
};