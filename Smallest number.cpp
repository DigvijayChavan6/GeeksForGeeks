// Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. Return a string that is the smallest possible number. If it is not possible then return -1.

// Examples:

// Input: s = 9, d = 2
// Output: 18 
// Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.
// Input: s = 20, d = 3 
// Output: 299 
// Explanation: 299 is the smallest number possible with the sum of digits = 20 and total digits = 3.
// Expected Time Complexity: O(d)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ s ≤ 100
// 1 ≤ d ≤ 6

class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(s>9*d || (s==0 && d>1))return "-1";
        if(s == 0 && d == 1)return "0";
        string ans="";
        for(int i=0;i<d;i++)ans+="9";
        long long total=static_cast<long long>(9*d)-s;
        int j=1, t;
        if(total<9){
            ans[0]-=total;
            total=0;
        }else{
            ans[0]='1';
            total-=8;
        }
        while(j<d && total){
            if(total>9){
                total-=9;
                ans[j]='0';
            }else{
                ans[j]-=total;
                total=0;
            }
            j++;
        }
        return ans;
    }
};