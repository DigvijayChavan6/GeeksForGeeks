// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears strictly more than N/2 times in the array.
 

// Example 1:

// Input:
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element.

// Example 2:

// Input:
// N = 5 
// A[] = {3,1,3,3,2} 
// Output:
// 3
// Explanation:
// Since, 3 is present more
// than N/2 times, so it is 
// the majority element.


// Your Task:
// The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).
 

// Constraints:
// 1 ≤ N ≤ 107
// 0 ≤ Ai ≤ 106

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        if(size==1)return a[0];
        int s=(size/2);
        sort(a,a+size);
        for(int i=0;i<s;i++){
            if(a[i]==a[i+s])return a[i];
        }
        return -1;
        
    }
};
