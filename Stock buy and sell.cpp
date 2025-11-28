class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        int maxProfit = 0;
        int n = arr.size();
        
        for(int i = 1; i < n; i++){
            int growth = arr[i] - arr[i-1];
            maxProfit += max(0, growth);
        }
        
        return maxProfit;
    }
};