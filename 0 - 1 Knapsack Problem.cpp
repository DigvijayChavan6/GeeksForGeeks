// Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

// Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

// Examples :

// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
// Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
// Output: 0
// Explanation: Every item has a weight exceeding the knapsack's capacity (3).
// Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
// Output: 80
// Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
// Constraints:
// 2 ≤ val.size() = wt.size() ≤ 103
// 1 ≤ W ≤ 103
// 1 ≤ val[i] ≤ 103
// 1 ≤ wt[i] ≤ 103

class Solution {
    vector<vector<int>> dp;
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        dp.assign(val.size()+1, vector<int>(W+1, -1));
        int i = 0;
        int sumW = 0;
        return getMax(W, val, wt, i, sumW);
    }
    
    
    
    int getMax(int W, vector<int> &val, vector<int> &wt, int i, int sumW){
        if(i >= val.size()){
            return 0;
        }
        if(dp[i][sumW] != -1){
            return dp[i][sumW];
        }
        int take = 0;
        if(wt[i]+sumW <= W){
            take = val[i] + getMax(W, val, wt, i+1, wt[i]+sumW);
        }
        int leave = getMax(W, val, wt, i+1, sumW);
        
        return dp[i][sumW] = max(leave, take);
    }
};