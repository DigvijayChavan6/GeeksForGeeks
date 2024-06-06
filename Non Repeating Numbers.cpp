// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.

// Example 1:

// Input: 
// N = 2
// arr[] = {1, 2, 3, 2, 1, 4}
// Output:
// 3 4 
// Explanation:
// 3 and 4 occur exactly once.

// Example 2:

// Input:
// N = 1
// arr[] = {2, 1, 3, 2}
// Output:
// 1 3
// Explanation:
// 1 3 occur exactly once.

// Your Task:
// You do not need to read or print anything. Your task is to complete the function singleNumber() which takes the array as input parameter and returns a list of two numbers which occur exactly once in the array. The list must be in ascending order.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)

// Constraints:
// 2 <= N <= 106 
// 1 <= arr[i] <= 5 * 106

class Solution{
public:
    vector<int> singleNumber(vector<int> nums) {
        // Code here.
        vector<int> vec;
        int sum=0;
        for(int val : nums){
            sum^=val;
        }
        sum=sum & -sum;
        int n=0, m=0;
        for(int val : nums){
            if((sum & val) == 0){
                n^=val;
            }else{
                m^=val;
            }
        }
        vec.push_back(n);
        vec.push_back(m);
        sort(vec.begin(), vec.end());
        return vec;
        // map<int,int>mp;
        // vector<int>v;
        // for(auto i:nums){
        //     mp[i]++;
        // }
        // for(auto i:mp){
        //     if(i.second==1){
        //         v.push_back(i.first);
        //     }
        // }
        // return v;
    }
};