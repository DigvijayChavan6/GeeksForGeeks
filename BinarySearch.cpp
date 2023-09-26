// find given key by using binary search

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==k)return mid;
            else if(arr[mid]<k)l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};