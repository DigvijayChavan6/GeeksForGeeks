// Given a n x n matrix such that each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from top left corner of the matrix to the bottom right. From a cell (i, j), you can only move to (i+1, j) or (i, j+1).

// Example 1:

// Input:
// k = 12, n = 3
// arr[] = [[1, 2, 3], 
//        [4, 6, 5], 
//        [3, 2, 1]]
// Output: 
// 2
// Explanation: 
// There are 2 possible paths with exactly 12 coins, (1 + 2 + 6 + 2 + 1) and (1 + 2 + 3 + 5 + 1).
// Example 2:

// Input:
// k = 16, n = 3
// arr[] = [[1, 2, 3], 
//        [4, 6, 5], 
//        [9, 8, 7]]
// Output: 
// 0 
// Explanation: 
// There are no possible paths that lead to sum=16
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function numberOfPath() which takes n, k and 2D matrix arr[][] as input parameters and returns the number of possible paths.

// Expected Time Complexity: O(n*n*k)
// Expected Auxiliary Space: O(n*n*k)

// Constraints:

// 1 <= k < 100
// 1 <= n < 100
// 0 <= arrij <= 200

class Solution {
public:
    
    void getCount(int i, int j, int n, int k, long long &cnt, vector<vector<int>> &arr){
        if(i==n || j==n)return;
        k=k-arr[i][j];
        if(i+1==n && j+1==n && k==0)cnt++;
        if(k<0)return;
        getCount(i+1,j,n,k,cnt,arr);
        getCount(i,j+1,n,k,cnt,arr);
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        long long cnt=0;
        getCount(0,0,n,k,cnt,arr);
        return cnt;
    }
    
};


// OPTIMISED ANSWER

class Solution {
public:

    long long getCount(int i, int j,int k, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp){
        if(i<0 || j<0)return 0;
        k=k-arr[i][j];
        if(k<0)return 0;
        if(i==0 && j==0 && k==0)return 1;
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        long long r=getCount(i-1,j,k,arr,dp);
        long long c=getCount(i,j-1,k,arr,dp);
        return dp[i][j][k]=r+c;
    }
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (n,vector<int> (k,-1)));
        return getCount(n-1,n-1,k,arr,dp);
    }
    
};