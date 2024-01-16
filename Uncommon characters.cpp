// Given two strings A and B consisting of lowercase english characters. Find the characters that are not common in the two strings. 

// Note :- Return the string in sorted order.

// Example 1:

// Input:
// A = geeksforgeeks
// B = geeksquiz
// Output: fioqruz
// Explanation: 
// The characters 'f', 'i', 'o', 'q', 'r', 'u','z' 
// are either present in A or B, but not in both.
// Example 2:

// Input:
// A = characters
// B = alphabets
// Output: bclpr
// Explanation: The characters 'b','c','l','p','r' 
// are either present in A or B, but not in both.

// Your Task:  
// You dont need to read input or print anything. Complete the function UncommonChars() which takes strings A and B as input parameters and returns a string that contains all the uncommon characters in sorted order. If no such character exists return "-1".


// Expected Time Complexity: O(M+N) where M and N are the sizes of A and B respectively.
// Expected Auxiliary Space: O(M+N)  


// Constraints:
// 1<= M,N <= 104
// String may contain duplicate characters.

class Solution{
    public:
        string UncommonChars(string A, string B){
            // code here
            string ans="";
            vector<bool> store(26,false);
            vector<bool> bstore(26,false);
            for(char c : A){
                c=c-97;
                store[c]=true;
            }
            for(char c : B){
                c=c-97;
                bstore[c]=true;
            }
            for(int i=0;i<26;i++){
                char c=97+i;
                if(store[i]!=bstore[i])ans+=c;
            }
            if(ans=="")return "-1";
            return ans;
        }
};