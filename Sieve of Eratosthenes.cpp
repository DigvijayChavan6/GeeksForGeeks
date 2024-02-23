// Given a number N, calculate the prime numbers up to N using Sieve of Eratosthenes.  

// Example 1:

// Input:
// N = 10

// Output:
// 2 3 5 7

// Explanation:
// Prime numbers less than equal to N 
// are 2 3 5 and 7.
// Example 2:

// Input:
// N = 35

// Output:
// 2 3 5 7 11 13 17 19 23 29 31

// Explanation:
// Prime numbers less than equal to 35 are
// 2 3 5 7 11 13 17 19 23 29 and 31.
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function sieveOfEratosthenes() which takes an integer N as an input parameter and return the list of prime numbers less than equal to N.

// Expected Time Complexity: O(NloglogN)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1<= N <= 104

class Solution{
public:
    void get(vector<bool> &vec,int n){
        for(int i=2;i*i<=n;i++){
            if(vec[i]){
                for(int j=i*i;j<=n;j+=i){
                    vec[j]=false;
                }
            }
        }
    }
    vector<int> sieveOfEratosthenes(int N){
        vector<bool> vec(N+1,true);
        get(vec,N);
        vector<int> ans;
        for(int i=2;i<=N;i++){
            if(vec[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};