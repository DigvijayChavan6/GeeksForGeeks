// Some people(n) are standing in a queue. A selection process follows a rule where people standing on even positions are selected. Of the selected people a queue is formed and again out of these only people on even position are selected. This continues until we are left with one person. Find out the position of that person in the original queue.

// Example 1:

// Input: n = 5
// Output: 4 
// Explanation: 1,2,3,4,5 -> 2,4 -> 4.


// Example 2:

// Input: n = 9
// Output: 8
// Explanation: 1,2,3,4,5,6,7,8,9
// ->2,4,6,8 -> 4,8 -> 8. 


// Your Task:  
// You dont need to read input or print anything. Complete the function nthPosition() which takes n as input parameter and returns the position(original queue) of that person who is left.

// Expected Time Complexity: O(logn)
// Expected Auxiliary Space: O(1)

// Constraints:
// 2<= n <=108

class Solution {
  public:
    long long int nthPosition(long long int n){
        long long int prev=2, cur=2;
        while(cur<=n){
            prev=cur;
            cur=cur*2;
        }
        return prev;
    }
};