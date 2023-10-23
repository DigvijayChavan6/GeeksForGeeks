// Given a binary array A[] of size N. The task is to arrange the array in increasing order.
// Note: The binary array contains only 0  and 1.
 

// Example 1:

// Input: 
// 5
// 1 0 1 1 0

// Output: 
// 0 0 1 1 1

// Explanation: 
// After arranging the elements in 
// increasing order, elements will be as 
// 0 0 1 1 1.

// Example 2:

// Input:
// 10
// 1 0 1 1 1 1 1 0 0 0

// Output: 
// 0 0 0 0 1 1 1 1 1 1

// Explanation: 
// After arranging the elements in 
// increasing order, elements will be 
// 0 0 0 0 1 1 1 1 1 1.

// Your Task: This is a function problem. You only need to complete the function binSort() that takes the array A[] and it's size N as parameters and sorts the array. The printing is done automatically by the driver code.

// Expected Time Complexity: O(N)
// Expected Auxilliary Space: O(1)

// Constraints:
// 1 <= N <= 106
// 0 <= A[i]<= 1

class Solution{
  public:
    
    // A[]: input array
    // N: input array
    //Function to sort the binary array.
    void binSort(int A[], int N)
    {
    //   int z=0;
    //   for(int i=0;i<N;i++)if(A[i]==0)z++;
    //   for(int i=0;i<z;i++)A[i]=0;
    //   for(int i=z;i<N;i++)A[i]=1;
        int l=0;
        for(int i=0;i<N;i++){
            if(A[i]==0){
                A[i]=A[l];
                A[l++]=0;
            }
        }
    }
};
