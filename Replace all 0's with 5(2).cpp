// You are given an integer N. You need to convert all zeroes of N to 5.

// Example 1:

// Input:
// N = 1004
// Output: 1554
// Explanation: There are two zeroes in 1004
// on replacing all zeroes with "5", the new
// number will be "1554".
// Example 2:

// Input:
// N = 121
// Output: 121
// Explanation: Since there are no zeroes in
// "121", the number remains as "121".
// Your Task:
// Your task is to complete the function convertFive() which takes an integer N as an argument and replaces all zeros in the number N with 5. Your function should return the converted number.

// Expected Time Complexity: O(K) where K is the number of digits in N
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <= 10000

int make(int n){
    int val=0;
    while(n != 0){
        int r=n%10;
        if(r==0)r=5;
        val=val*10 + r;
        n/=10;
    }
    return val;
}

int convertFive(int n) {
    return make(make(n));
}