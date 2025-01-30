// The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

// Given an integer n, find all distinct solutions to the n-queens puzzle.
// You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
// For eg. below figure represents a chessboard [3 1 4 2].



// Examples:

// Input: n = 1
// Output: [1]
// Explaination: Only one queen can be placed in the single cell available.
// Input: n = 4
// Output: [[2 4 1 3 ] [3 1 4 2 ]]
// Explaination: There are 2 possible solutions for n = 4.
// Input: n = 2
// Output: []
// Explaination: There are no possible solutions for n = 2.
// Constraints:
// 1 ≤ n ≤ 10

class Solution {
    vector<vector<int>> answer, board;
    
    void solve(int col, int n){
        if(col >= n){
            getSolution(n);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(isSafe(i, col, n)){
                board[i][col] = 1;
                solve(col+1, n);
                board[i][col] = 0;
            }
        }
    }
    
    bool isSafe(int row, int col, int n){
        for(int j = 0; j < n; j++){
            if(board[row][j] == 1){
                return false;
            }
        }
        
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 1){
                return false;
            }
        }
        
        for(int i = row, j = col; i < n && j >= 0; i++, j--){
            if(board[i][j] == 1){
                return false;
            }
        }
        
        return true;
    }
    
    void getSolution(int n){
        vector<int> temp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 1){
                    temp.push_back(j+1);
                }
            }
        }
        answer.push_back(temp);
    }
    
  public:
    vector<vector<int>> nQueen(int n) {
        // code here
        board.assign(n, vector<int>(n, 0));
        solve(0, n);
        return answer;
    }
};