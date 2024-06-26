// Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

// Example 1:

// Input:
// A[] = {1, 4, 45, 6, 0, 19}
// x  =  51
// Output: 3
// Explanation:
// Minimum length subarray is 
// {4, 45, 6}


// Example 2:

// Input:
// A[] = {1, 10, 5, 2, 7}
//    x  = 9
// Output: 1
// Explanation:
// Minimum length subarray is {10}

 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function smallestSubWithSum() which takes the array A[], its size N and an integer X as inputs and returns the required ouput.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N, x ≤ 105
// 0 ≤ A[] ≤ 104

class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x){
        // Your code goes here   
        long long cursum=0;
        int size=INT_MAX;
        int l=0, h=0;
        while(h<n){
            cursum+=arr[h];
            while(cursum>x){
                size=min(size, h-l+1);
                cursum-=arr[l++];
            }
            h++;
        }
        if(size==INT_MAX)return 0;
        return size;
    }
};
