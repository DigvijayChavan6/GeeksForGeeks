// Given an unsorted array, find the minimum difference between any pair in given array.
 

// Example 1:

// Input: nums = [2, 4, 5, 9, 7]
// Output: 1
// Explanation: Difference between 5 and 4 is 1.
// Example 2:

// Input: nums = [3, 10, 8, 6]
// Output: 2
// Explanation: Difference between 8 and 6 is 2.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function minimum_difference() which takes the array as input parameter and returns the minimum difference  between any pair in given array.

// Expected Time Compelxity: O(N* log(N)) where N is length of array.
// Expected Space Complexity: O(1)
 

// Constraints:
// 2 <= N <= 105
// 1 <= nums[i] <= 109

class Solution
{
public:
    int minimum_difference(vector<int> nums)
    {
        int mn = INT_MAX;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < size; i++)
        {
            mn = min(mn, nums[i] - nums[i - 1]);
        }
        return mn;
    }
};