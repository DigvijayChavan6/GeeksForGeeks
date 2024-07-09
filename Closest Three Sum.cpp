// Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

// Note: If there are multiple solutions, return the maximum one.

// Examples :

// Input: arr[] = [-7, 9, 8, 3, 1, 1], target = 2
// Output: 2
// Explanation: There is only one triplet present in the array where elements are -7,8,1 whose sum is 2.
// Input: arr[] = [5, 2, 7, 5], target = 13
// Output: 14
// Explanation: There is one triplet with sum 12 and other with sum 14 in the array. Triplet elements are 5, 2, 5 and 2, 7, 5 respectively. Since abs(13-12) ==abs(13-14) maximum triplet sum will be preferred i.e 14.
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 3 ≤ arr.size() ≤ 103
// -105 ≤ arr[i] ≤ 105
// 1 ≤ target ≤ 105

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int size=arr.size();
        int ans=INT_MIN;
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                int l=j+1, h=size-1;
                while(l<=h){
                    int mid=l+(h-l)/2;
                    int sum=arr[i]+arr[j]+arr[mid];
                    if(sum == target)return sum;
                    else if(sum < target)l=mid+1;
                    else h=mid-1;
                    int a=abs(sum-target);
                    int b=abs(ans-target);
                    if( (a<b )|| (a == b && sum>target) )ans=sum;
                }
            }
        }
        return ans;
        // TC is O(N^3) and SC is O(1) i.e. constant
        // int size=arr.size();
        // int ans=INT_MIN;
        // for(int i=0;i<size;i++){
        //     for(int j=i+1;j<size;j++){
        //         for(int k=j+1;k<size;k++){
        //             int sum=arr[i]+arr[j]+arr[k];
        //             if(sum == target)return sum;
        //             int a=abs(sum-target);
        //             int b=abs(ans-target);
        //             if( (a<b )|| (a == b && sum>target) )ans=sum;
        //         }
        //     }
        // }
        // return ans;
    }
};