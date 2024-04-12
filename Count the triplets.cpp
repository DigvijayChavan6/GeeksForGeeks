// Given an array Arr consisting of N distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
 

// Example 1:

// Input: 
// N = 4 
// arr[] = {1, 5, 3, 2}
// Output: 2 
// Explanation: There are 2 triplets:
//  1 + 2 = 3 and 3 +2 = 5


// Example 2:

// Input: 
// N = 3
// arr[] = {2, 3, 4}
// Output: 0
// Explanation: No such triplet exits

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function countTriplet() which takes the array arr[] and N as inputs and returns the triplet count

// Expected Time Complexity: O(N2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ N ≤ 103
// 1 ≤ arr[i] ≤ 105

class Solution{
public:	
	
	int countTriplet(int arr[], int n){
	    sort(arr, arr+n);
	    int cnt = 0;
	    for(int i=0;i<n-2;i++){
	        for(int j=i+1;j<n-1;j++){
	            int l=j+1, h=n-1;
	            int sum=arr[i]+arr[j];
	            while(l<=h){
	                int mid = l+(h-l)/2;
	                if(sum == arr[mid]){
	                    cnt++;
	                    break;
	                }
	                else if(sum < arr[mid])h=mid-1;
	                else l=mid+1;
	            }
	        }
	    }
	    return cnt;
	}
};

//OPTIMISED

class Solution{
public:	
	
	int countTriplet(int arr[], int n){
	    sort(arr, arr+n);
	    int cnt = 0;
	    for(int i=n-1;i>=0;i--){
	        int l=0, h=i-1;
	        while(l<h){
	            if(arr[i] == arr[l]+arr[h]){
	                cnt ++;
	                l++;
	                h--;
	            }
	            else if(arr[i] > arr[l]+arr[h])l++;
	            else h--;
	        }
	    }
	    return cnt;
	}
};