// You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

// At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.

// Examples:

// Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
// Output: 3
// Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
// Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
// Output: 1
// Explanation: All train times are mutually exclusive. So we need only one platform
// Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
// Output: 3
// Explanation: All 3 trains have to be there from 11:00 to 11:30
// Constraints:
// 1≤ number of trains ≤ 50000
// 0000 ≤ arr[i] ≤ dep[i] ≤ 2359
// Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0).

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here

        vector<vector<int>> t;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < arr.size(); i++){
            t.push_back({arr[i], dep[i]});
        }
        
        sort(t.begin(), t.end());
        
        int available = 0, m = 1;
        
        pq.push(t[0][1]);

        for(int i = 1; i < arr.size(); i++){
            
            while(!pq.empty() && pq.top() < t[i][0]){
                available++;
                pq.pop();    
            }
            
            if(t[i][0] <= t[i-1][1]){
                if(available == 0)m++;
                else available--;
            }else{
                available--;
            }
            
            pq.push(t[i][1]);
        }
        
        return m;
    }
};
