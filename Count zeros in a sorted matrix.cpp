// Given a N X N binary Square Matrix where each row and column of the matrix is sorted in ascending order. Find the total number of zeros present in the matrix.

// Example 1:

// Input:
// N = 3
// A = {{0, 0, 0},
//      {0, 0, 1},
//      {0, 1, 1}}
// Output: 6
// Explanation: 
// The first, second and third row contains 3, 2 and 1
// zeroes respectively.
// Example 2:

// Input:
// N = 2
// A = {{1, 1},
//      {1, 1}}
// Output: 0
// Explanation:
// There are no zeroes in any of the rows.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function countZeros() which takes a 2D matrix as input and returns the number occurring only once.

// Expected Time Complexity: O(N ).
// Expected Auxiliary Space: O(1).

// Constraints
// 0 <   N  <= 103
// 0 <= A[i] <= 1

class Solution{
public:
	int countZeros(vector<vector<int>>A){
		//code here
		int N=A.size();
		int cnt=0, i=0;
		while(i<N){
		    int l=0, h=N-1;
		    while(l<=h){
		        int mid=l+(h-l)/2;
		        if(A[i][mid]==0){
		            l=mid+1;
		        }else{
		            h=mid-1;
		        }
		    }
		    cnt+=l;
		    i++;
		}
		return cnt;
	}
};