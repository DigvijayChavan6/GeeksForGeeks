https://www.geeksforgeeks.org/problems/word-search/1?page=1&category=Backtracking&difficulty=Basic,Easy,Medium&status=unsolved&sortBy=submissions

// Given a 2D board of letters and a word. Check if the word exists in the board. The word can be constructed from letters of adjacent cells only. ie - horizontal or vertical neighbors. The same letter cell can not be used more than once.

// Example 1:

// Input: board = {{a,g,b,c},{q,e,e,l},{g,b,k,s}},
// word = "geeks"
// Output: 1
// Explanation: The board is-
// a g b c
// q e e l
// g b k s
// The letters which are used to make the
// "geeks" are colored.

// Example 2:

// Input: board = {{a,b,c,e},{s,f,c,s},{a,d,e,e}},
// word = "sabfs"
// Output: 0
// Explanation: The board is-
// a b c e
// s f c s
// a d e e
// Same letter can not be used twice hence ans is 0

// Your Task:
// You don't need to read or print anything. Your task is to complete the function isWordExist() which takes board and word as input parameter and returns boolean value true if word can be found otherwise returns false.

// Expected Time Complexity: O(N * M * 4L) where N = No. of rows in board, M = No. of columns in board, L = Length of word
// Expected Space Compelxity: O(L), L is length of word.

// Constraints:
// 1 ≤ N, M ≤ 100
// 1 ≤ L ≤ N*M

class Solution {
    int row, col, n;
    void checkFor(int index, string word, vector<vector<char>> &board, int r, int c, bool &answer){
        if(answer || index == n)return ;
        if(!answer && r+1<row && board[r+1][c] == word[index]){
            if(index+1 == n){
                answer=true;
                return ;
            }
            board[r+1][c]='0';
            checkFor(index+1, word, board, r+1, c, answer);
            board[r+1][c]=word[index];
        }
        if(!answer && c+1<col && board[r][c+1] == word[index]){
            if(index+1 == n){
                answer=true;
                return ;
            }
            board[r][c+1]='0';
            checkFor(index+1, word, board, r, c+1, answer);
            board[r][c+1]=word[index];
        }
        if(!answer && r-1>=0 && board[r-1][c] == word[index]){
            if(index+1 == n){
                answer=true;
                return ;
            }
            board[r-1][c]='0';
            checkFor(index+1, word, board, r-1, c, answer);
            board[r-1][c]=word[index];
        }
        if(!answer && c-1>=0 && board[r][c-1] == word[index]){
            if(index+1 == n){
                answer=true;
                return ;
            }
            board[r][c-1]='0';
            checkFor(index+1, word, board, r, c-1, answer);
            board[r][c-1]=word[index];
        }
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        bool answer=false;
        n=word.size();
        row=board.size();
        col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(word[0] == board[i][j]){
                    if(n == 1)return true;
                    board[i][j]='0';
                    checkFor(1, word, board, i, j, answer);
                    board[i][j]=word[0];
                }
                if(answer)return true;
            }
        }
        return false;
    }
};