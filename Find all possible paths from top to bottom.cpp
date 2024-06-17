// Given a N x M grid. Find All possible paths from top left to bottom right.From each cell you can either move only to right or down.

// Example 1:

// Input: 1 2 3
//        4 5 6
// Output: 1 4 5 6
//         1 2 5 6 
//         1 2 3 6
// Explanation: We can see that there are 3 
// paths from the cell (0,0) to (1,2).

// Example 2:

// Input: 1 2
//        3 4
// Output: 1 2 4
//         1 3 4

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findAllPossiblePaths() which takes two integers n,m and grid[][]  as input parameters and returns all possible paths from the top left cell to bottom right cell in a 2d array.

// Expected Time Complexity: O(2^N*M)
// Expected Auxiliary Space: O(N)


// Constraints:
// 1 <= n,m <= 10 
// 1 <= grid[i][j] <= n*m
// n * m < 20
 
class Solution{
    int a, b;
    vector<vector<int>> vec;
    void getPaths(vector<vector<int>> &grid, vector<int> temp, int i, int j){
        if(i == a || j == b)return ;
        temp.push_back(grid[i][j]);
        if(i+1 == a && j+1 == b){
            vec.push_back(temp);
            return;
        }
        getPaths(grid, temp, i+1, j);
        getPaths(grid, temp, i, j+1);
    }
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid){
        // code here
        vector<int> temp;
        a=n; b=m;
        getPaths(grid, temp, 0, 0);
        return vec;
    }
};