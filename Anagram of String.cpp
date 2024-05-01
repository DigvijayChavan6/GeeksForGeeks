// Given two strings S1 and S2 in lowercase, the task is to make them anagram. The only allowed operation is to remove a character from any string. Find the minimum number of characters to be deleted to make both the strings anagram. Two strings are called anagram of each other if one of them can be converted into another by rearranging its letters.

// Example 1:

// Input:
// S1 = bcadeh
// S2 = hea
// Output: 3
// Explanation: We need to remove b, c
// and d from S1.

// Example 2:

// Input:
// S1 = cddgk
// S2 = gcd
// Output: 2
// Explanation: We need to remove d and
// k from S1.

// Your Task:
// Complete the function remAnagram() which takes two strings S1, S2 as input parameter, and returns minimum characters needs to be deleted.

// Expected Time Complexity: O(max(|S1|, |S2|)), where |S| = length of string S.
// Expected Auxiliary Space: O(26)

// Constraints:
// 1 <= |S1|, |S2| <= 105

void addFreq(string s, vector<int> &a){
    for(char c : s){
        a[c-97]++;
    }
}
int remAnagram(string str1, string str2){
    // Your code goes here
    int del=0;
    vector<int> a(26, 0);
    vector<int> b(26, 0);
    addFreq(str1, a);
    addFreq(str2, b);
    for(int i=0;i<26;i++){
        del+=(abs(a[i]-b[i]));
    }
    return del;
}