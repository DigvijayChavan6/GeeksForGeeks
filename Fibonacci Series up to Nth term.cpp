// You are given integer N, and return the Fibonacci Series till the Nth term.

// Example:

// Input:
// 5
// Output:
// 0 1 1 2 3 5
// Explanation:
// 0 1 1 2 3 5 is the Fibonacci series up to
// the 5th term.(0-based indexing)
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function Series() which takes an Integer N as input and returns a Fibonacci Series up to the Nth term.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraint:
// 1<=n<100

class Solution {
  public:
    void get(vector<long long> &vec,int a, int b, int N){
        if(N==0)return;
        long long sum=vec[a]+vec[b];
        vec.push_back(sum);
        get(vec,a+1,b+1,--N);
    }
    vector<long long> Series(int N){
        if(N==0)return {0};
        if(N==1)return {0,1};
        vector<long long> vec;
        vec.push_back(0);
        vec.push_back(1);
        get(vec,0,1,N-1);
        return vec;
    }
};