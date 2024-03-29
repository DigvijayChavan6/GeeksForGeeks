// Given a sorted array having N elements, find the indices of the first and last occurrences of an element X in the given array.

// Note: If the number X is not found in the array, return '-1' as an array.

// Example 1:

// Input:
// N = 4 , X = 3
// arr[] = { 1, 3, 3, 4 }
// Output:
// 1 2
// Explanation:
// For the above array, first occurence
// of X = 3 is at index = 1 and last
// occurence is at index = 2.
// Example 2:

// Input:
// N = 4, X = 5
// arr[] = { 1, 2, 3, 4 }
// Output:
// -1
// Explanation: 
// As 5 is not present in the array,
// so the answer is -1.
// Your Task:
// You don't need to read input or print anything. Complete the function firstAndLast() that takes the array arr, its size N and the value X as input parameters and returns a list of integers containing the indices of first and last occurence of X.

// Expected Time Complexity: O(log(N))
// Expected Auxiliary Space: O(1)

// Constraints: 
// 1 <= N <= 10^5 

// 0 <= arr[i], X <= 109

class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid] == x){
                i=mid;
                j=mid;
                while(arr[i] == x)i--;
                while(arr[j] == x)j++;
                return {i+1,j-1};
            }
            else if(arr[mid] < x)i=mid+1;
            else j=mid-1;
        }
        return {-1};
    }
};