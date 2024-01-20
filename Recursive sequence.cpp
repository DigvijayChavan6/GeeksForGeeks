// A function f is defined as follows F(N)= (1) +(2*3) + (4*5*6) ... N. Given an integer N the task is to print the F(N)th term.

// Example 1:

// Input: N = 5
// Output: 365527
// Explaination: F(5) = 1 + 2*3 + 4*5*6 + 7*8*9*10 
// + 11*12*13*14*15 = 365527.
// Your Task:
// You do not need to readd input or print anything. Your task is to complete the function sequence() which takes N as input parameter and returns the value of F(N).

// Expected Tiime Complexity: O(N2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 10

class Solution{
public:
    long long make(int N,int &count,int g){
        if(g>N)return 0;
        long long sum=1;
        for(int i=1;i<=g;i++){
            sum=sum*count++;
        }
        return sum + make(N,count,++g);
    }
    long long sequence(int N){
        int c=1;
        return make(N,c,1); 
    }
};
