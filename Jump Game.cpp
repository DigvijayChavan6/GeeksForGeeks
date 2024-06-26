// Given an positive integer N and a list of N integers A[]. Each element in the array denotes the maximum length of jump you can cover. Find out if you can make it to the last index if you start at the first index of the list.


// Example 1:

// Input:
// N = 6
// A[] = {1, 2, 0, 3, 0, 0} 
// Output:
// 1
// Explanation:
// Jump 1 step from first index to
// second index. Then jump 2 steps to reach 
// 4th index, and now jump 2 steps to reach
// the end.

// Example 2:

// Input:
// N = 3
// A[] =  {1, 0, 2}
// Output:
// 0
// Explanation:
// You can't reach the end of the array.


// Your Task:
// You don't need to read input or print anything. Your task is to complete the function canReach() which takes a Integer N and a list A of size N as input and returns 1 if the end of the array is reachable, else return 0.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 <= N <= 105
// 0 <= A[i] <= 105

class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        int mxReach=0;
        for(int i=0;i<N;i++){
            if(mxReach >= N-1)break;
            if(mxReach < i)return false;
            mxReach=max(mxReach, i+A[i]);
        }
        return true;
    }
};