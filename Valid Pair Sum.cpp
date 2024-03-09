// Given an array of size N, find the number of distinct pairs {i, j} (i != j) in the array such that the sum of a[i] and a[j] is greater than 0.

// Example 1:

// Input: N = 3, a[] = {3, -2, 1}
// Output: 2
// Explanation: {3, -2}, {3, 1} are two 
// possible pairs.
// Example 2:

// Input: N = 4, a[] = {-1, -1, -1, 0}
// Output: 0
// Explanation: There are no possible pairs.
// Your Task:  
// You don't need to read input or print anything. Complete the function ValidPair() which takes the array a[ ] and size of array N as input parameters and returns the count of such pairs.

// Expected Time Complexity: O(N * Log(N))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 105 
// -104  ≤ a[i] ≤ 104

class Solution{
    
    public:
    long long ValidPair(int a[], int n) {
        long long cnt=0;
        sort(a, a+n);
        for(int i=0;i<n;i++){
            int l=i+1, h=n-1;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(a[mid] + a[i] > 0){
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            cnt+=(n-l);
        }
        return cnt;
    }   
};