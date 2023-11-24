// Given a positive integer N, return the Nth row of pascal's triangle.
// Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
// The elements can be large so return it modulo 109 + 7.

// File:PascalTriangleAnimated2.gif

// Example 1:

// Input:
// N = 4
// Output: 
// 1 3 3 1
// Explanation: 
// 4th row of pascal's triangle is 1 3 3 1.
// Example 2:

// Input:
// N = 5
// Output: 
// 1 4 6 4 1
// Explanation: 
// 5th row of pascal's triangle is 1 4 6 4 1.
// Your Task:
// Complete the function nthRowOfPascalTriangle() which takes n, as input parameters and returns an array representing the answer. You don't to print answer or take inputs.

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(N2)

// Constraints:
// 1 ≤ N ≤ 103

class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        if(n==1)return {1};
        n--;
        vector<long long> vec(2,1);
        if(n==1)return vec;
        n--;
        for(int i=1;i<=n;i++){
            long long int rsum=0,size=vec.size();
            vector<long long> tempVec;
            tempVec.push_back(1);
            for(long long knt=1;knt<size;knt++){
                rsum=vec[knt-1]+vec[knt];
                rsum=rsum%1000000007;
                tempVec.push_back(rsum);
            }
            tempVec.push_back(1);
            vec=tempVec;
        }
        return vec;
    }
};