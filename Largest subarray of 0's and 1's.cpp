// Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

// Examples:

// Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
// Output: 6
// Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.
// Input: arr[] = [0, 0, 1, 1, 0]
// Output: 4
// Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.
// Input: arr[] = [0]
// Output: 0
// Explnation: There is no subarray with an equal number of 0s and 1s.
// Constraints:
// 1 <= arr.size() <= 105
// 0 <= arr[i] <= 1

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int cnt = 0, sum = 0;
        
        map<int, int> mp;
        
        for(int i = 0; i < arr.size(); ++i){
            int val = arr[i];
            if(val == 1){
                sum++;
            }else{
                sum--;
            }
            
            if(sum == 0){
                cnt = max(cnt, i+1);
            }
            
            if(mp.find(sum) != mp.end()){
                cnt = max(cnt, i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        
        return cnt;
    }
     
    // Brute Force    
    //     int cnt = 0;
        
    //     for(int i = 0; i < arr.size(); i++){
    //         int one = 0, zero = 0;
    //         for(int j = i; j < arr.size(); j++){
    //             if(arr[j] == 1)one++;
    //             else zero++;
                
    //             if(one == zero){
    //                 cnt = max(cnt, j-i+1);
    //             }
    //         }
    //     }
        
    //     return cnt;

};