// Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

// Note: Return 1 if there exists any such pair otherwise return -1.

// Example 1:

// Input: n = 6, m = 4, a[] = {4, 1, 2, 1, 1, 2}, b[] = (3, 6, 3, 3)
// Output: 1
// Explanation: Sum of elements in a[] = 11, Sum of elements in b[] = 15, To get same sum from both arrays, we can swap following values: 1 from a[] and 3 from b[]

// Example 2:

// Input: n = 4, m = 4, a[] = {5, 7, 4, 6}, b[] = {1, 2, 3, 8}
// Output: 1
// Explanation: We can swap 6 from array a[] and 2 from array b[]

// Expected Time Complexity: O(mlogm+nlogn).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ n, m ≤ 106
// 0 <= a[i], b[i] <= 105

class Solution {
    long long int getSum(int a[], int n){
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        return sum;
    }
  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        long long int asum=getSum(a, n);
        long long int bsum=getSum(b, m);
        long long int sum=asum+bsum;
        if(sum%2 == 1)return -1;
        long long int eq=sum/2;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
        }
        for(int i=0;i<m;i++){
            int key=bsum-b[i];
            if(mp[eq-key]>0)return 1;   
        }
        return -1;
    }
};