// A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

// Example 1

// Input:
// N = 5
// arr[] = {4 ,5 ,1 ,2 ,3}
// Output: 1
// Explanation: 1 is the minimum element in the array.

// Example 2

// Input:
// N = 7
// arr[] = {10, 20, 30, 40, 50, 5, 7}
// Output: 5
// Explanation: Here 5 is the minimum element.

 

// Your Task:
// Complete the function findMin() which takes an array arr[] and n, size of the array as input parameters, and returns the minimum element of the array.

// Expected Time Complexity: O(log N).
// Expected Auxiliary Space: O(log N).

// Constraints:
// 1 ≤ N ≤ 100000
// 1 ≤ A[i] ≤ 1000000

class Solution{
public:
    int findMin(int arr[], int n){
        int answer = INT_MAX;
        int l=0, h=n-1;
        while(l<h){
            int mid=l+(h-l)/2;
            answer=min(answer, arr[mid]);
            answer=min(answer, arr[l]);
            answer=min(answer, arr[h]);
            if(arr[mid]>arr[l]){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return answer;
    }
};