// https://www.geeksforgeeks.org/problems/find-number-of-numbers/1?page=1&difficulty=Basic&status=unsolved&sortBy=submissions


// Given an array A[]  of n elements. Your task is to complete the Function num which returns an integer denoting the total number of times digit k appears in the whole array.

// For Example:

// Input:
// A[] = {11,12,13,14,15}, k=1
// Output:
// 6 
// Explanation: Here digit 1 appears in the whole array 6 times.

// Your Task:

// You don't need to read input or print anything. Complete the function Num() which accepts an integer N and array A as input parameter and return the desired output.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<=T<=100
// 1<=n<=20
// 1<=A[]<=1000

int num(int a[], int n, int k){
    //add code here.
    int cnt=0;
    for(int i=0;i<n;i++){
        int t=a[i];
        while(t){
            if(k == t%10)cnt++;
            t/=10;
        }
    }
    return cnt;
}