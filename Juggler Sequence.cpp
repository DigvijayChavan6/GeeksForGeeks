// Juggler Sequence is a series of integers in which the first term starts with a positive integer number a and the remaining terms are generated from the immediate previous term using the below recurrence relation:

// Juggler Formula

// Given a number n, find the Juggler Sequence for this number as the first term of the sequence until it becomes 1.


// Example 1:

// Input: n = 9
// Output: 9 27 140 11 36 6 2 1
// Explaination: We start with 9 and use 
// above formula to get next terms.

 

// Example 2:

// Input: n = 6
// Output: 6 2 1
// Explaination: 
// [61/2] = 2. 
// [21/2] = 1.

 

// Your Task:
// You do not need to read input or print anything. Your Task is to complete the function jugglerSequence() which takes n as the input parameter and returns a list of integers denoting the generated sequence.

 

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

 

// Constraints:
// 1 ≤ n ≤ 100

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long> vec;
        vec.push_back(n);
        long long i=0, val=1, v;
        while(vec[i] != 1){
            v=vec[i];
            if(vec[i]%2 == 0){
                val=pow(v, .5);
            }
            else{
                val=pow(v, 1.5);
            }
            vec.push_back(val);
            i++;
        }
        return vec;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends