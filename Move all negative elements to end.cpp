// Given an unsorted array arr[] of size n having both negative and positive integers. The task is place all negative element at the end of array without changing the order of positive element and negative element.

 

// Example 1:

// Input : 
// n = 8
// arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }
// Output : 
// 1  3  2  11  6  -1  -7  -5


// Example 2:

// Input : 
// n = 8
// arr[] = {-5, 7, -3, -4, 9, 10, -1, 11}
// Output :
// 7  9  10  11  -5  -3  -4  -1

 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function segregateElements() which takes the array arr[] and its size N as inputs and store the answer in the array arr[] itself.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)
 
// Constraints:
// 1 ≤ n ≤ 106
// -109 ≤ arr[i] ≤ 109

class Solution
{
public:
    void segregateElements(int arr[], int n)
    {
        vector<int> vec(arr, arr + n);
        int i = 0;
        for (int k = 0; k < n; k++)
        {
            if (vec[k] >= 0)
            {
                arr[i++] = vec[k];
            }
        }
        for (int k = 0; k < n; k++)
        {
            if (vec[k] < 0)
            {
                arr[i++] = vec[k];
            }
        }
    }
};