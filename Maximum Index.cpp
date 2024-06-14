// Given an array a of n positive integers. The task is to find the maximum of j - i subjected to the constraint of a[i] < a[j] and i < j.

// Example 1:

// Input:
// n = 2
// a[] = {1, 10}
// Output:
// 1
// Explanation:
// a[0] < a[1] so (j-i) is 1-0 = 1.

// Example 2:

// Input:
// n = 9
// a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
// Output:
// 6
// Explanation:
// In the given array a[1] < a[7] satisfying the required condition(a[i] < a[j]) thus giving the maximum difference of j - i which is 6(7-1).

// Your Task:
// The task is to complete the function maxIndexDiff() which takes array a[] and integer n as input and returns the maximum index difference.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 ≤ n ≤ 106
// 0 ≤ a[i] ≤ 109

class Solution{
    public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) { 
        // Your code here
        vector<int> mx(n+1, 0);
        vector<int> mn(n+1, 0);
        int small=INT_MAX;
        for(int i=0;i<n;i++){
            mn[i]=min(small, a[i]);
            small=mn[i];
        }
        int big=INT_MIN;
        for(int i=n-1;i>=0;i--){
            mx[i]=max(big, a[i]);
            big=mx[i];
        }
        int i=0, j=0, max_dif=0;
        while(i<n && j<n){
            if(mn[i] <= mx[j]){
                max_dif=max(max_dif, j-i);
                j++;
            }else{
                i++;
            }
        }
        return max_dif;
    }
};

        // int mx_dif=0;
        // int low=0, high=n-1;
        // while(low <= high){
        //     if(a[low] <= a[high]){
        //         mx_dif=max(mx_dif, high-low);
        //         high=n-1;
        //         low++;
        //     }else{
        //         high--;
        //     }
        // }
        // return mx_dif;