// Given a two-dimensional integer array arr of dimensions n x n, consisting solely of zeros and ones, identify the row or column (using 0-based indexing) where all elements form a palindrome. If multiple palindromes are identified, prioritize the palindromes found in rows over those in columns. Within rows or columns, the palindrome with the smaller index takes precedence. The result should be represented by the index followed by either 'R' or 'C', indicating whether the palindrome was located in a row or column. The output should be space-separated. If no palindrome is found, return the string -1.

// Examples:

// Input: 
// arr[][] =  [[1, 0, 0], 
//            [0, 1, 0],
//            [1, 1, 0]]
// Output: 1 R
// Explanation: In the first test case, 0-1-0 is a palindrome 
// occuring in a row having index 1.

// Input: 
// arr[][] =   [[1, 0],
//            [1, 0]]
// Output: 0 C
// Explanation: 1-1 occurs before 0-0 in the 0th column. And there is no palindrome in the two rows.

// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<= arr.size <= 50
// 0 <= arr[i][j] <= 1

class Solution {
    bool forRows(vector<int> &v, int l, int h){
        while(l<h){
            if(v[l] != v[h]){
                return false;
            }
            l++; h--;
        }
        return true;  
    }
    bool forCols(vector<vector<int>> &arr, int c, int h){
        int l=0;
        while(l<h){
            if(arr[l][c] != arr[h][c]){
                return false;
            }
            l++; h--;
        }
        return true;
    }
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        string answer="";
        int row=arr.size(), col=arr[0].size();
        for(int i=0;i<row;i++){
            if(forRows(arr[i], 0, col-1)){
                answer+=to_string(i);
                answer+=" R";
                return answer;
            }
        }
        for(int i=0;i<col;i++){
            if(forCols(arr, i, row-1)){
                answer+=to_string(i);
                answer+=" C";
                return answer;
            }
        }
        return "-1";
    }
};
