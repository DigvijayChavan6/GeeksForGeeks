// Given two strings denoting non-negative numbers X and Y. Calculate the sum of X and Y.


// Example 1:

// Input:
// X = "25", Y = "23"
// Output:
// 48
// Explanation:
// The sum of 25 and 23 is 48.
// Example 2:

// Input:
// X = "2500", Y = "23"
// Output:
// 2523
// Explanation:
// The sum of 2500 and 23 is 2523.

// Your Task:
// Your task is to complete the function findSum() which takes two strings as inputs and returns the string without leading zeros. You do not need to take any input or print anything.


// Expected Time Complexity: O(|X| + |Y|)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 <= |X|, |Y| <= 105

class Solution {
    string removeZero(string s){
        string ans = "";
        
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != '0'){
                return s.substr(i);
            }else{
                ans = "0";
            }
        }
        
        return ans;
    }
  public:
    string findSum(string X, string Y) {
        // Your code goes here
        
        
        X = removeZero(X);
        Y = removeZero(Y);
        
        string sum = "";
        
        int i = X.size()-1, j = Y.size()-1;
        int carry = 0;
        
        while(i >= 0  && j >= 0){
            int a = X[i]-48;
            int b = Y[j]-48;
            int s = a+b+carry;
            
            carry = (s >= 10) ? 1 : 0;
            
            sum = (char)((s%10)+48)  + sum;
            
            --i; --j;
        }
        while(i >= 0){
            int a = X[i]-48;
            int s = a+carry;
            
            carry = (s >= 10) ? 1 : 0;
            
            sum = (char)((s%10)+48)  + sum;
            
            --i;
        }while(j >= 0){
            int b = Y[j]-48;
            int s = b+carry;
            
            carry = (s >= 10) ? 1 : 0;
            
            sum = (char)((s%10)+48)  + sum;
            
            --j;
        }
        if(carry == 1){
            sum = "1" + sum;
        }
        return sum;
    }
};