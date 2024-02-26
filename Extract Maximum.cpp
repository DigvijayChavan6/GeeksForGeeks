// Given a alphanumeric string S, extract maximum numeric value from S.

// Example 1:

// Input:
// S = 100klh564abc365bg
// Output: 564
// Explanation: Maximum numeric value 
// among 100, 564 and 365 is 564.
// Example 2:

// Input:
// S = abcdefg
// Output: -1
// Explanation: Return -1 if no numeric 
// value is present. 

// Your Task:  
// You dont need to read input or print anything. Complete the function extractMaximum() which takes the string S as input parameters and returns the maximum numeric value. If it is not present in S, return -1.

 

// Expected Time Complexity: O(|S|)
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 1 ≤ |S| ≤ 104
// -1 ≤ output value ≤ 106

class Solution{
  public:
    
    int extractMaximum(string S) { 
        int ans = INT_MIN;
        int temp = 0;
        int size = S.size();
        bool flag = true;
        for(int i = 0; i < size; i++){
            char c = S[i];
            if(c <= 57 && c >= 48){
                temp = temp * 10 + c-48;
                flag = false;
            }
            else{
                ans = max(temp, ans);
                temp = 0;
            }
        }
        ans = max(temp, ans);
        if(flag)return -1;
        return ans;
    } 
};
