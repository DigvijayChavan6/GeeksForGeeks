// You are given an array arr. Your task is to find the longest length of a good sequence. A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations :

// 1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
// 2.  x1 >x2 < x3 > x4 < x5. . . . . and so on

// Examples:

// Input: arr= [1, 5, 4]
// Output: 3
// Explanation: The entire sequenece is a good sequence.
// Input: arr= [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
// Output: 7
// Explanation: There are several subsequences that achieve this length. 
// One maximum length good subsequences is [1, 17, 10, 13, 10, 16, 8].
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= nums.size() <= 105 
// 1 <= nums[i] <= 104 

class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code for longest subsequence for above conditions
        int n=arr.size();
        if(n==0)return 0;
        int big=1, small=1;
        for(int i=1;i<n;i++){
            if(arr[i-1]<arr[i]){
                big=small+1;
            }else if(arr[i-1]>arr[i]){
                small=big+1;
            }
        }
        return max(big, small);
    }    
    // code to find largest subarray for above conditions
    //     int len=INT_MIN, cnt=0, flag=-1, n=arr.size();
    //     if(n<3)return 0;
    //     for(int i=1;i<n-1;i++){
    //         bool zero=(arr[i-1]>arr[i] && arr[i+1]>arr[i]);
    //         bool one=(arr[i-1]<arr[i] && arr[i+1]<arr[i]);
    //         if(zero || one){
    //             if(flag==-1){
    //                 cnt++;
    //                 if(one)flag=1;
    //                 if(zero)flag=0;
    //             }
    //             if(zero && flag==1){
    //                 cnt++;
    //                 flag=0;
    //             }else{
    //                 len=max(len, cnt);
    //                 cnt=1;
    //             }
    //             if(one && flag==0){
    //                 cnt++;
    //                 flag=1;
    //             }else{
    //                 len=max(len, cnt);
    //                 cnt=1;
    //             }
    //             len=max(len, cnt);
    //         }
    //         else{
    //             len=max(len, cnt);
    //             cnt=0;
    //             flag=-1;
    //         }
    //     }
    //     return len+2;
    // 
};