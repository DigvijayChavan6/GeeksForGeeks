// Given a string S, remove all consonants and print the modified string that contains vowels only.

// Example 1:

// Input
// S = "abEkipo"
// Output
// aEio
// Explanation : a, E, i, o are only vowels in the string.
// Example 2:

// Input
// S = "rrty"
// Output
// No Vowel
// Explanation: There are no vowels.

// Your Task: You don't need to read input or print anything.Your task is to complete the function removeConsonants() which takes a string as input parameters, and returns the modified string that contains vowels only. If there is no vowel present in the string S, then return "No Vowel".

// Expected Time Complexity: O(|S|).
// Expected Auxiliary Space: O(1).

// Constraints
// 1 <= |S| <= 105
// The string should consist of only alphabets.

class Solution{
    public:
    string removeConsonants(string s){
    //complete the function heredef removeConsonants(s):
        string answer="";
        for(auto c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
               c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                
                answer+=c;
            }
        }
        if(answer=="")return "No Vowel";
        return answer;
    }
};