// You are given a positive integer N, return the sum of all prime numbers between 1 and N(inclusive).
 

// Example 1:

// Input: N = 5
// Output: 10
// Explanation: 2, 3, and 5 are prime
// numbers between 1 and 5(inclusive), and their sum is 2 + 3 + 5 = 10.
// Example 2:

// Input: N = 10
// Output: 17
// Explanation: 2, 3, 5 and 7 are prime
// numbers between 1 and 10(inclusive), and their sum is 2 + 3 + 5 + 7 = 17.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function prime_Sum() which takes integer N as an input parameter and returns the sum of all primes between 1 and N(inclusive).
 

// Expected Time Complexity: O(N*log(N))
// Expected Space Complexity: O(N)

// Constraints:
// 1 <= N <= 1000000

class Solution{
	public:
	
	void sieve(vector<bool> &prime, int n){
	    for(int i=2;i*i<=n;i++){
	        if(prime[i]){
	            for(int j=i*i;j<=n;j+=i){
	                prime[j]=false;
	            }
	        }
	    }
	}
	
   	long long int prime_Sum(int n){
   	    vector<bool> prime(n+1,true);
   	    sieve(prime,n+1);
        long long int sum=0;
        for(int i=2;i<=n;i++){
            if(prime[i])sum+=i;
        }
        return sum;
   	}   
   	
};