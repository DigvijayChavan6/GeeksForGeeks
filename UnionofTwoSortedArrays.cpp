// Union of two arrays can be defined as the common and distinct elements in the two arrays.
// Given two sorted arrays of size n and m respectively, find their union.


// Example 1:

// Input: 
// n = 5, arr1[] = {1, 2, 3, 4, 5}  
// m = 3, arr2 [] = {1, 2, 3}
// Output: 1 2 3 4 5
// Explanation: Distinct elements including 
// both the arrays are: 1 2 3 4 5.

 

// Example 2:

// Input: 
// n = 5, arr1[] = {2, 2, 3, 4, 5}  
// m = 5, arr2[] = {1, 1, 2, 3, 4}
// Output: 1 2 3 4 5
// Explanation: Distinct elements including 
// both the arrays are: 1 2 3 4 5.

 

// Example 3:

// Input:
// n = 5, arr1[] = {1, 1, 1, 1, 1}
// m = 5, arr2[] = {2, 2, 2, 2, 2}
// Output: 1 2
// Explanation: Distinct elements including 
// both the arrays are: 1 2.


// Your Task: 
// You do not need to read input or print anything. Complete the function findUnion() that takes two arrays arr1[], arr2[], and their size n and m as input parameters and returns a list containing the union of the two arrays. 
 

// Expected Time Complexity: O(n+m).
// Expected Auxiliary Space: O(n+m).
 

// Constraints:
// 1 <= n, m <= 105
// 1 <= arr[i], brr[i] <= 106


class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int a[], int b[], int n, int m){
        vector<int> vec;
        int i=0,j=0;
        while(i<n&&j<m){
            if(a[i]<b[j]){
                if(vec.empty()||vec.back()!=a[i])vec.push_back(a[i]);
                i++;
            }
            else if(b[j]<a[i]){
                if(vec.empty()||vec.back()!=b[j])vec.push_back(b[j]);
                j++;
            }
            else{
                if(vec.empty()||vec.back()!=b[j])vec.push_back(a[i]);
                i++;
                j++;
            }
        }
        while(i<n){
            if(vec.empty()||vec.back()!=a[i])vec.push_back(a[i]);
            i++;
        }
        while(j<m){
            if(vec.empty()||vec.back()!=b[j])vec.push_back(b[j]);
            j++;
        }
        return vec;
    }
};
