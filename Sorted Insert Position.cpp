class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int index = 0;
            int l = 0, r = arr.size() - 1;

            while(l <= r){
                int mid = l + (r-l)/2;
                if(k == arr[mid]){
                    return mid;
                }else if(arr[mid] < k){
                    l = mid + 1;
                    index = l;
                }else{
                    r = mid - 1;
                }
            }

            return index;
    }
};