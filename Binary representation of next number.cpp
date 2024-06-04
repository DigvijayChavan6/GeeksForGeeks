// Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.

// Note: Output binary string should not contain leading zeros.

// Example 1:

// Input: s = "10"
// Output: 11
// Explanation: "10" is the binary representation of 2 and binary representation of 3 is "11"

// Example 2:

// Input: s = "111"
// Output: 1000
// Explanation: "111" is the binary representation of 7 and binary representation of 8 is "1000"

// Your Task:  
// You don't need to read input or print anything. Complete the function binaryNextNumber()which takes s as input parameter and returns the string.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n) to store resultant string  

// Constraints:
// 1 <= n <= 105

class Solution {
  public:
    // int getNum(string s){
    //     int n=0, k=0;
    //     for(int i=s.size()-1;i>=0;i--){
    //         if(s[i] == '1')n+=pow(2, k);
    //         k++;
    //     }
    //     return n;
    // }
    // string getBinary(int n){
    //     string s="";
    //     while(n){
    //         if(n%2)s="1"+s;
    //         else s="0"+s;
    //         n/=2;
    //     }
    //     return s;
    // }
    void makeZero(string &s, int p, int n){
        for(int k=p;k<n;k++)s[k]='0';
    }
    void removeZero(string &s, int n){
        string k=s;
        for(int i=0;i<n;i++){
            if(s[i] == '1')break;
            k=k.substr(1, n);
        }
        s=k;
    }
    string binaryNextNumber(string s) {
        int n=s.size();
        bool flag=true;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0'){
                s[i]='1';
                makeZero(s, i+1, n);
                flag=false;
                break;
            }
        }
        if(flag){
            s="1"+s;
            makeZero(s,1, n+1);
        }
        removeZero(s, n);
        return s;
        // int n=getNum(s);
        // return getBinary(++n);
    }
};
