

class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        vector<int> temp;
        temp.push_back(arr[0]);
        int n = arr.size();
        int len = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
                len++;
            }else{
                auto ind = lower_bound(temp.begin(), temp.end(), arr[i]);
                *ind = arr[i];
            }
        }
        
        return len;
    }
};