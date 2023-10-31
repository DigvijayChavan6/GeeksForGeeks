// Register for free now
// banner

// Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

// Example 1:

// Input: 
// N = 4 , M = 4
// Arr[][] = {{0, 1, 1, 1},
//            {0, 0, 1, 1},
//            {1, 1, 1, 1},
//            {0, 0, 0, 0}}
// Output: 2
// Explanation: Row 2 contains 4 1's (0-based
// indexing).


// Example 2:

// Input: 
// N = 2, M = 2
// Arr[][] = {{0, 0}, {1, 1}}
// Output: 1
// Explanation: Row 1 contains 2 1's (0-based
// indexing).


// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.
 

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ N, M ≤ 103
// 0 ≤ Arr[i][j] ≤ 1 

 
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int mx=0,ind=-1;
	    for(int i=0;i<n;i++){
	        int t=0;
	        for(int j=m-1;j>=0;j--)if(arr[i][j]==1)t++;
	        if(t>mx){
	            mx=t;
	            ind=i;
	        }
	    }
	    return ind;
	}

};
