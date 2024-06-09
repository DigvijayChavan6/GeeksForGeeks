// Geek is very fond of patterns. Once, his teacher gave him a  pattern to solve. He gave Geek an integer n and asked him to build a pattern.

// Help Geek to build a pattern.

 

// Example 1:

// Input: 5

// Output:

// *********
//  *******
//   *****
//    ***
//     *

// Your Task:

// You don't need to input anything. Complete the function printTriangle() which takes  an integer n  as the input parameter and print the pattern.

// Constraints:

//     1<= N <= 20

class Solution{
public:
	
	void printTriangle(int n) {
	    // code here
	    int i=n*2;
	    int r=n;
	    if(i%2 == 0)i--;
	    while(r){
	        for(int s=1;s<=n-r;s++){
	            cout<<" ";
	        }
	        for(int p=1;p<=i;p++){
	            cout<<"*";
	        }
	        cout<<endl;
	        i-=2;
	        r--;
	    }
	}
};
