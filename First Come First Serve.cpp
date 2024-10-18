// You are given an array arr[], containing the IDs of users in chronological order of their occurrences. Find the first user who has exactly k occurrences.
// If no such user exists, return -1.

// Examples:

// Input: arr[] = [1, 7, 4, 3, 4, 8, 7] , k = 2
// Output: 7
// Explanation: Both 7 and 4 occur 2 times. But 7 is the first that occurs 2 times.  
// Input: arr[] = [4, 1, 6, 1, 6, 4] , k = 1 
// Output: -1 
// Explanation: No one occurs exactly 1 time.
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 1 ≤ arr[i] ≤ 106

class Solution {
  public:
    int firstElement(vector<int>& arr, int k) {
        // write code here
        map<int, int> mp;
        int n=arr.size();
        for(int i=0; i<n; ++i){
            mp[arr[i]]++;
        }
        for(int i=0; i<n; ++i){
            if(mp[arr[i]] == k){
                return arr[i];
            }
        }
        return -1;
    }
};