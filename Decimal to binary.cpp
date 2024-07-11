// Given a decimal number N, compute its binary equivalent.

// Example 1:

// Input: N = 7
// Output: 111
 

// Example 2:

// Input: N = 33
// Output: 100001

void toBinary(int N){
    // your code here
    string bin="";
    while(N){
        int p=N&1;
        if(p)bin="1"+bin;
        else bin="0"+bin;
        N/=2;
    }   
    cout<<bin;
}