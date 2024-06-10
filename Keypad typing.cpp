// You are given a n length string S of lowercase alphabet characters and the task is to find its matching decimal representation as on the shown keypad. Output the decimal representation corresponding to the string. For ex: if you are given amazon then its corresponding decimal representation will be 262966.

// Example 1:

// Input:
// S = geeksforgeeks
// Output: 4335736743357
// Explanation:geeksforgeeks is 4335736743357
// in decimal when we type it using the given
// keypad.

// Example 2:

// Input:
// S = geeksquiz
// Output: 433577849
// Explanation: geeksquiz is 433577849 in
// decimal when we type it using the given
// keypad.

// Your Task:
// Complete printNumber() function that takes string s and its length as parameters and returns the corresponding decimal representation of the given string as a string type. The printing is done by the driver code.

// Constraints:
// 1 ≤ length of String ≤ 100

// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(n)

string printNumber(string s, int n) {
    //code here
    map<char, char> mp={ {'a', '2'}, {'b', '2'}, {'c', '2'}, {'d', '3'}, 
    {'e', '3'}, {'f', '3'}, {'g', '4'}, {'h', '4'}, {'i', '4'}, {'j', '5'}, 
    {'k', '5'}, {'l', '5'}, {'m', '6'}, {'n', '6'}, {'o', '6'}, {'p', '7'}, 
    {'q', '7'}, {'r', '7'}, {'s', '7'}, {'t', '8'}, {'u', '8'}, {'v', '8'},
    {'w', '9'}, {'x', '9'}, {'y', '9'}, {'z', '9'} }; 
    string answer="";
    for(char c : s){
        answer+=mp[c];
    }
    return answer;
}