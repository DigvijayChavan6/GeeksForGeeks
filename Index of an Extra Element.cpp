// You have given two sorted arrays arr1[] & arr2[] of distinct elements. The first array has one element extra added in between. Return the index of the extra element.

// Note: 0-based indexing is followed.

// Examples

// Input: n = 7, arr1[] = {2,4,6,8,9,10,12}, arr2[] = {2,4,6,8,10,12}
// Output: 4
// Explanation: In the first array, 9 is extra added and it's index is 4.

// Input: n = 6, arr1[] = {3,5,7,8,11,13}, arr2[] = {3,5,7,11,13}
// Output: 3
// Explanation: In the first array, 8 is extra and it's index is 3.

// Expected Time Complexity: O(log n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1<=n<=105
// 1<=arr1[i],arr2[i]<=106

class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        if(n == 1 || arr2[0] != arr1[0])return 0;
        int low=0, high=n-1, answer=n-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(arr1[mid] == arr2[mid]){
                low=mid+1;
            }else{
                high=mid-1;
                answer=mid;
            }
        }
        return answer;
        // if(n == 1 || arr2[0]!=arr1[0])return 0;
        // for(int i=1;i<n-1;i++){
        //     if(arr2[i]!=arr1[i]){
        //         if(arr2[i-1]!=arr1[i]){
        //             if(arr2[i+1]!=arr1[i])return i;
        //         }
        //     }
        // }
        // return n-1;
    }
};

