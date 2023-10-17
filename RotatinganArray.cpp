// Given an array of size N. The task is to rotate array by D elements where D ≤ N.

// Example 1:

// Input:
// N = 7
// Arr[] = {1, 2, 3, 4, 5, 6, 7}
// D = 2
// Output: 3 4 5 6 7 1 2
// Explanation: 
// Rotate by 1: [2, 3, 4, 5, 6, 7, 1]
// Rotate by 2: [3, 4, 5, 6, 7, 1, 2]


// Example 2:

// Input:
// N = 4
// Arr[] = {1, 3, 4, 2}
// D = 3
// Output: 2 1 3 4

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function leftRotate() which takes the array of integers arr[], its size n and d as input parameters and rotates arr[] in-place without using any extra memory.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Arr[i] ≤ 1000
// 0 ≤ D ≤ N

class Solution{   
public:
    void leftRotate(int arr[], int n, int d) {
        // code here
        // while(d!=0){
        // int tp=arr[0];
        // for(int i=1;i<n;i++)arr[i-1]=arr[i];
        // arr[n-1]=tp;
        // d--;
        // }  THIS IS BRUITE FORCE SOLUTION
        
        // queue<int> q;
        // for(int i=0;i<d;i++)q.push(arr[i]);
        // int j;
        // for(j=0;j<n-d;j++)arr[j]=arr[j+d];
        // while(!q.empty()){
        //     arr[j++]=q.front();
        //     q.pop();
        // }  THIS IS BETTER OR SLIGHTLY OPTIMUM SOLUTION
        
        for(int i=0;i<n/2;i++){
            int t=arr[i];
            arr[i]=arr[n-1-i];
            arr[n-1-i]=t;
        }
        int s=n-d;
        for(int i=0;i<s/2;i++){
            int t=arr[i];
            arr[i]=arr[s-1-i];
            arr[s-1-i]=t;
        }
        for(int i=s,j=n-1;i<(s+n+1)/2;i++,j--){
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }  
        // THIS IS MOST OPTIMAL SOLUTION
    }
};
