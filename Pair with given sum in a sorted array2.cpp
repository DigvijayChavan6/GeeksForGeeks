// You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
// Note: pairs should have elements of distinct indexes. 

// Examples :

// Input: arr[] = [-1, 1, 5, 5, 7], target = 6
// Output: 3
// Explanation: There are 3 pairs which sum up to 6 : {1, 5}, {1, 5} and {-1, 7}.
// Input: arr[] = [1, 1, 1, 1], target = 2
// Output: 6
// Explanation: There are 6 pairs which sum up to 2 : {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1} and {1, 1}.
// Input: arr[] = [-1, 10, 10, 12, 15], target = 125
// Output: 0
// Explanation: There is no such pair which sums up to 4.
// Constraints:
// -105 <= target <=105
//  2 <= arr.size() <= 105
// -105 <= arr[i] <= 105



class Solution {
  public:
    int countPairs(vector<int> &arr, int sum) {
        // Complete the function
        int n = arr.size();
        int cnt = 0;
        int i=0, j=n-1;
        while(i<j){
            if(arr[i]+arr[j] == sum){
                int a = 0, b = 0, ii = arr[i], jj = arr[j];
                
                while(i <= j && arr[i] == ii){
                    a++;
                    i++;
                }
                while(j >= i && arr[j] == jj){
                    b++;
                    j--;
                }
                
                if(ii == jj){
                    cnt += (a*(a-1))/2;
                }else{
                    cnt += (a*b);
                }
            }
            else if(arr[i]+arr[j] < sum){
                i++;
            }
            else{
                j--;
            }
        }
        return cnt;
    }
};

//         int cnt = 0;
//         unordered_map<int, int> mp;
        
//         for(int v : arr){
//             if(mp[sum-v] > 0){
//                 cnt += mp[sum-v];
//             }
//             mp[v]++;
//         }

//         return cnt;
