// Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
// The description of cells is as follows:

// A value of cell 1 means Source.
// A value of cell 2 means Destination.
// A value of cell 3 means Blank cell.
// A value of cell 0 means Wall (blocked cell which we cannot traverse).
// Note: There are only a single source and a single destination.
 

// Examples :

// Input: grid = {{3,0,3,0,0},{3,0,0,0,3},{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
// Output: 0
// Explanation: The grid is-
// 3 0 3 0 0 
// 3 0 0 0 3 
// 3 3 3 3 3 
// 0 2 3 0 0 
// 3 0 0 1 3 
// There is no path to reach at (3,1) i,e at destination from (4,3) i,e source.
// Input: grid = {{1,3},{3,2}}
// Output: 1
// Explanation: The grid is-
// 1 3
// 3 2
// There is a path from (0,0) i,e source to (1,1) i,e destination.
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)
 

// Constraints:
// 1 ≤ n ≤ 500

class Solution {
    int n, m;
    
    bool isPath(vector<vector<int>> &grid, int a, int b) {
        if (a < 0 || b < 0 || a >= n || b >= m || grid[a][b] == 0) {
            return false;
        }
        if (grid[a][b] == 2) {
            return true;
        }
        
        grid[a][b] = 0;
        
        return isPath(grid, a + 1, b) || isPath(grid, a - 1, b) || isPath(grid, a, b + 1) || isPath(grid, a, b - 1);
    }
    
public:
    bool is_Possible(vector<vector<int>>& grid) {
        int a = -1, b = -1;
        n = grid.size(), m = grid[0].size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    a = i;
                    b = j;
                    break;
                }
            }
            if (a != -1) break;
        }
        
        return isPath(grid, a, b);
    }
};