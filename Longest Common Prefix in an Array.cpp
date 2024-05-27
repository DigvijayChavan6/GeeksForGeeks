// Given an array of N strings, find the longest common prefix among all strings present in the array.


// Example 1:

// Input:
// N = 4
// arr[] = {geeksforgeeks, geeks, geek,
//          geezer}
// Output: gee
// Explanation: "gee" is the longest common
// prefix in all the given strings.

// Example 2:

// Input: 
// N = 2
// arr[] = {hello, world}
// Output: -1
// Explanation: There's no common prefix
// in the given strings.


// Your Task:
// You don't need to read input or print anything. Your task is to complete the function longestCommonPrefix() which takes the string array arr[] and its size N as inputs and returns the longest common prefix common in all the strings in the array. If there's no prefix common in all the strings, return "-1".


// Expected Time Complexity: O(N*min(|arri|)).
// Expected Auxiliary Space: O(min(|arri|)) for result.


// Constraints:
// 1 ≤ N ≤ 103
// 1 ≤ |arri| ≤ 103

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N){
        // your code here
        string str="";
        int size=INT_MAX;
        for(int i=0;i<N;i++){
            int s=arr[i].size();
            size=min(size, s);
        }
        for(int i=0;i<size;i++){
            int cnt=0;
            for(int j=1;j<N;j++){
                if(arr[j][i] != arr[0][i]){
                    if(str == "") return "-1";
                    return str;
                }
            }
            str+=arr[0][i];
        }
        return str;
    }
};
