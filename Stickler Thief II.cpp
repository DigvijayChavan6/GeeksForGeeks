class Solution {
    int getMax(int s, int n, vector<int> &arr){
        int a = arr[n], b = 0;
        for(int i = n-1; i >= s; i--){
            int skip = a;
            int take = b + arr[i];
            b = a; 
            a = max(take, skip);
        }
        return a;
    }
  public:
    int maxValue(vector<int>& arr) {
        // code here
        int n = arr.size();
        return max(getMax(1, n-1, arr), getMax(0, n-2, arr));
    }
};
