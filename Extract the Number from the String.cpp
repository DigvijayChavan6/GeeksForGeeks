// Given a sentence containing several words and numbers. Find the largest number among them which does not contain 9. If no such number exists, return -1.

// Note: Numbers and words are separated by spaces only. It is guaranteed that there are no leading zeroes in the answer.

// Examples :

// Input: sentence="This is alpha 5057 and 97"
// Output: 5057
// Explanation: 5057 is the only number that does not have a 9.

// Input: sentence="Another input 9007"
// Output: -1
// Explanation: Since there is no number that does not contain a 9,output is -1.

// Expected Time Complexity: O(n)
// Expected Auxillary Space: O(n)

// Constraints:
// 1<=n<=106
// 1<=answer<=1018

// n is the length of a given sentence.

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        long long num=-1;
        long long temp=0;
        bool flag=true;
        for(char c : sentence){
            if(c>=48 && c<=57){
                if(c-48 == 9){
                    temp=0;
                    flag=false;
                }
                temp=temp*10 + (c-48);
            }else{
                if(temp != 0 && flag){
                    num=max(num, temp);
                }
                temp=0;
                flag=true;
            }
        }
        if(flag)num=max(num, temp);
        return num;
    }
};