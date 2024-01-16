// This is a functional problem. Your task is to return the product of array elements under a given modulo.
// The modulo operation finds the remainder after the division of one number by another. For example, K(mod(m))=K%m= remainder obtained when K is divided by m

// Example:

// Input:
// 1
// 4
// 1 2 3 4

// Output:
// 24
// Input:
// The first line of input contains T denoting the number of test cases. Then each of the T lines contains a single positive integer N denotes the number of elements in the array. The next line contains 'N' integer elements of the array.


// Output:
// Return the product of array elements under a given modulo.
// That is, return (Array[0]*Array[1]*Array[2]...*Array[n])%modulo.

// Constraints:
// 1<=T<=200
// 1<=N<=10^5
// 1<=ar[i]<=10^5

/*  
     ar[] is the array
     n = number of element in array
     mod = modulo value;
*/
long long int product(int ar[], int n, long long int mod){
    long long int pro=1;
    for(int i=0;i<n;i++){
        pro=((pro)*(ar[i]))%mod;
    }
    return pro;
}