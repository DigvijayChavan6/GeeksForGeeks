// Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


// Example 1:

// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]
// Output:
// 1
// Explanation:
// The triplet {1, 4, 8} in 
// the array sums up to 13.
// Example 2:

// Input:
// n = 5, X = 10
// arr[] = [1 2 4 3 6]
// Output:
// 1
// Explanation:
// The triplet {1, 3, 6} in 
// the array sums up to 10.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function find3Numbers() which takes the array arr[], the size of the array (n) and the sum (X) as inputs and returns True if there exists a triplet in the array arr[] which sums up to X and False otherwise.


// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ n ≤ 103
// 1 ≤ A[i] ≤ 105

class Solution{
    public:
    
    bool find3Numbers(int A[], int n, int x){
        sort(A, A+n);
        for(int i=0;i< n-2;i++){
            int low=i+1, high=n-1;
            while(low < high){
                int val=A[i] + A[low] + A[high];
                if(val == x)return true;
                else if(val > x)high--;
                else low++;
            }
        }
        return false;
    }

};
