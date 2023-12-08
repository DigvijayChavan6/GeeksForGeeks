// Given a sorted array arr[] of size N. Find the element that appears only once in the array. All other elements appear exactly twice. 

// Example 1:

// Input:
// N = 11
// arr[] = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65}
// Output: 4
// Explanation: 4 is the only element that 
// appears exactly once.
 

// Your Task:  
// You don't need to read input or print anything. Complete the function findOnce() which takes sorted array and its size as its input parameter and returns the element that appears only once. 


// Expected Time Complexity: O(log N)
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 1 <= N <= 105
// -105 <= arr[i] <= 105

class Solution{
  public:
    int findOnce(int arr[], int n){
        if(n==1)return arr[0];
        if(arr[0]!=arr[1])return arr[0];
        for(int i=1;i<n-1;i++){
            if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1])return arr[i];
        }
        return arr[n-1];
    }
};