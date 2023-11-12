// Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

 

// Example 1:

// Input:
// x = 5
// Output: 2
// Explanation: Since, 5 is not a perfect 
// square, floor of square_root of 5 is 2.
// Example 2:

// Input:
// x = 4
// Output: 2
// Explanation: Since, 4 is a perfect 
// square, so its square root is 2.
 

// Your Task:
// You don't need to read input or print anything. The task is to complete the function floorSqrt() which takes x as the input parameter and return its square root.
// Note: Try Solving the question without using the sqrt function. The value of x>=0.

 

// Expected Time Complexity: O(log N)
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 1 ≤ x ≤ 107

class Solution{
  public:
    long long int floorSqrt(long long int x) {
        long long int s=1;
        while(true){
            long long int z=s*s;
            if(z==x)return s;
            else if(z>x)return s-1;
            s++;
        }
        
    }
};
