// Given a string, s, the objective is to convert it into integer format without utilizing any built-in functions. If the conversion is not feasible, the function should return -1.

// Note: Conversion is feasible only if all characters in the string are numeric or if its first character is '-' and rest are numeric.

// Example 1:

// Input:
// s = "-123"
// Output: 
// -123
// Explanation:
// It is possible to convert -123 into an integer 
// and is so returned in the form of an integer
// Example 2:

// Input:
// s = "21a"
// Output: 
// -1
// Explanation: 
// The output is -1 as, due to the inclusion of 'a',
// the given string cannot be converted to an integer.
// Your Task:
// You do not have to take any input or print anything. Complete the function atoi() which takes a string s as an input parameter and returns an integer value representing the given string. If the conversion is not feasible, the function should return -1.

// |s| = length of string str.
// Expected Time Complexity: O( |s| ), 
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |s| ≤ 10

class Solution{
  public:
    int atoi(string s) {
        int val=0;
        int size=s.size();
        char d=s[0];
        if(d!=45){
            if(d<=57 && d>=48)val=d-48;
            else return -1;
        }
        for(int i=1;i<size;i++){
            d=s[i];
            if(d>57 || d<48)return -1;
            d=d-48;
            val=val*10+d;
        }
        if(s[0]=='-')val=val*(-1);
        return val;
    }
};