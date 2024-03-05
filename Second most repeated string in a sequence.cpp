// Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

// Note: No two strings are the second most repeated, there will be always a single string.

// Example 1:

// Input:
// N = 6
// arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
// Output: bbb
// Explanation: "bbb" is the second most 
// occurring string with frequency 2.

// Example 2:

// Input: 
// N = 6
// arr[] = {geek, for, geek, for, geek, aaa}
// Output: for
// Explanation: "for" is the second most
// occurring string with frequency 2.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function secFrequent() which takes the string array arr[] and its size N as inputs and returns the second most frequent string in the array. If no such string exists, then return an empty string.


// Expected Time Complexity: O(N*max(|Si|).
// Expected Auxiliary Space: O(N*max(|Si|).


// Constraints:
// 1<=N<=103


class Solution{
  public:
    string secFrequent (string arr[], int n){
        unordered_map<string, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int sec=INT_MIN, mx=INT_MIN;
        string s="", m=s;
        for(auto p : mp){
            if(p.second > mx){
                sec=mx;
                mx=p.second;
                s=m;
                m=p.first;
            }
            else if(p.second > sec){
                sec=p.second;
                s=p.first;
            }
        }
        return s;
    }
};
 