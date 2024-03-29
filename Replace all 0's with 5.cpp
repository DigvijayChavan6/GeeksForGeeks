// Given a number N. The task is to complete the function convertFive() which replaces all zeros in the number with 5 and returns the number.

// Example:

// Input
// 2
// 1004
// 121

// Output
// 1554
// 121

// Explanation:
// Testcase 1:  At index 1 and 2 there is 0 so we replace it with 5.
// Testcase 2: There is no,0 so output will remain the same.
// Input:
// The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow.
// Each test case contains a single integer N denoting the number.

// Output:
// The function will return an integer where all zero's are converted to 5.

// Your Task:
// Since this is a functional problem you don't have to worry about input, you just have to complete the function convertFive().

// Constraints:
// 1 <= T <= 103
// 1 <= N <= 104

class Solution{
  public:
  
    int convertFive(int n){
        int ans=0;
        while(n != 0){
            int r=n%10;
            if(r == 0)r=5;
            ans = ans*10+r;
            n/=10;
        }
        n=ans;
        ans=0;
        while(n != 0){
            int r=n%10;
            ans = ans*10+r;
            n/=10;
        }
        return ans;
    }
    
};