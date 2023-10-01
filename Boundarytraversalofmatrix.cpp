// You are given a matrix of dimensions n x m. The task is to perform boundary traversal on the matrix in a clockwise manner.

// Example 1:

// Input:
// n = 4, m = 4
// matrix[][] = {{1, 2, 3, 4},
//          {5, 6, 7, 8},
//          {9, 10, 11, 12},
//          {13, 14, 15,16}}
// Output: 1 2 3 4 8 12 16 15 14 13 9 5
// Explanation:
// The matrix is:
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// The boundary traversal is:
// 1 2 3 4 8 12 16 15 14 13 9 5
// Example 2:

// Input:
// n = 3, m = 4
// matrrix[][] = {{12, 11, 10, 9},
//          {8, 7, 6, 5},
//          {4, 3, 2, 1}}
// Output: 12 11 10 9 5 1 2 3 4 8
// Your Task:
// Complete the function boundaryTraversal() that takes matrix, n and m as input parameters and returns the list of integers that form the boundary traversal of the matrix in a clockwise manner.

// Expected Time Complexity: O(N + M)
// Expected Auxiliary Space: O(N+M)

// Constraints:
// 1 <= n, m<= 1000
// 0 <= matrixi <= 1000

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > mat, int n, int m) 
    {
        // code here
        vector<int> vec;
        for(int i=0;i<m;i++)vec.push_back(mat[0][i]);
        if(n==1)return vec;
        for(int i=1;i<n;i++)vec.push_back(mat[i][m-1]);
        if(m==1)return vec;
        for(int i=m-2;i>=0;i--)vec.push_back(mat[n-1][i]);
        for(int i=n-2;i>0;i--)vec.push_back(mat[i][0]);
        return vec;
    }
};