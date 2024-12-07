// Given an array of integers arr[]. Find the Inversion Count in the array.
// Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
// Input: arr[] = [2, 3, 4, 5, 6]
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.
// Input: arr[] = [10, 10, 10]
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.
// Constraints:
// 1 ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 104

class Solution {
    
    int join(vector<int> &arr, int left, int mid, int right){
        int count = 0;
        int lft = left, rgt = mid+1;
        vector<int> temp;
        
        while(lft <= mid && rgt <= right){
            if(arr[lft] <= arr[rgt]){
                temp.push_back(arr[lft]);
                ++lft;
            }else{
                count += (mid-lft+1);
                temp.push_back(arr[rgt]);
                ++rgt;
            }
        }
        
        while(lft <= mid){
            temp.push_back(arr[lft++]);
        }
        while(rgt <= right){
            temp.push_back(arr[rgt++]);
        }
        
        for(int i=left; i<=right; ++i){
            arr[i] = temp[i-left];
        }
        
        return count;
    }
    
    int getCount(vector<int> &arr, int left, int right){
        int count = 0;
        if(left < right){
            int mid = left + (right-left)/2;
            count += getCount(arr, left, mid);
            count += getCount(arr, mid+1, right);
            count += join(arr, left, mid, right);
        }
        return count;
    }
            
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        // int count = 0;
        // int N = arr.size();
    
        // for(int i=0;i<N;i++){
        //     for(int j=0;j<i;j++){
        //         if(arr[j]>arr[i]){
        //             count++;
        //         }
        //     }
        // }
        
        return getCount(arr, 0, arr.size()-1);
    }
};