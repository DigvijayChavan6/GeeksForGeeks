// Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage of all zeros of the matrix where coverage for a particular 0 is defined as a total number of ones around a zero in left, right, up and bottom directions.

// Examples:

// Input:
// matrix = [[0, 1, 0],
//           [0, 1, 1],
//           [0, 0, 0]]
// Output: 6
// Explanation: There are a total of 6 coverage are there

// Input: 
// matrix = [[0, 1]]
// Output: 1
// Explanation: There are only 1 coverage.

// Expected Time Complexity: O(n * m)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= matrix.size, matrix[0].size <= 100

class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int sum=0;
        int row=matrix.size(), col=matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int val=matrix[i][j];
                if(val == 0){
                    if(i-1>=0 && matrix[i-1][j] == 1)sum++;
                    if(i+1<row && matrix[i+1][j] == 1)sum++;
                    if(j-1>=0 && matrix[i][j-1] == 1)sum++;
                    if(j+1<col && matrix[i][j+1] == 1)sum++;
                }
            }
        }
        return sum;
    }
};