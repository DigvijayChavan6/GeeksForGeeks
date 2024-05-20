// Given a string str and another string patt. Find the minimum index of the character in str that is also present in patt.


// Example 1:

// Input:
// str = geeksforgeeks
// patt = set
// Output: 1
// Explanation: e is the character which is
// present in given str "geeksforgeeks"
// and is also present in patt "set". Minimum
// index of e is 1. 

// Example 2:

// Input:
// str = adcffaet
// patt = onkl
// Output: -1
// Explanation: There are none of the
// characters which is common in patt
// and str.


// Your Task:
// You only need to complete the function minIndexChar() that returns the index of answer in str or returns -1 in case no character of patt is present in str.


// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Number of distinct characters).


// Constraints:
// 1 ≤ |str|,|patt| ≤ 105 
// 'a' <= stri, patti <= 'z'


class Solution{
  public:
    //Function to find the minimum indexed character.
    int minIndexChar(string str, string patt){
        // Your code here
        map<char, bool> mp;
        for(char c : patt)mp[c]=true;
        int size=str.size();
        for(int i=0;i<size;i++){
            if(mp[str[i]])return i;
        }
        return -1;
    }
};