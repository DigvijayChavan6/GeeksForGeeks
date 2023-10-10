// Write a program to find the sum of the given series 1+2+3+ . . . . . .(N terms) 

// Example 1:

// Input:
// N = 1
// Output: 1
// Explanation: For n = 1, sum will be 1.
// Example 2:

// Input:
// N = 5
// Output: 15
// Explanation: For n = 5, sum will be 15.
// 1 + 2 + 3 + 4 + 5 = 15.
// Your Task:
// Complete the function seriesSum() which takes single integer n, as input parameters and returns an integer denoting the answer. You don't need to print the answer or take inputs.

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 105

class Solution{
public:
	// function to return sum of  1, 2, ... n
	long long seriesSum(int n) {
	    // code here
	    double re=(double)n/2;
	    long sum=re*(n+1);
	    return sum;
	}
};