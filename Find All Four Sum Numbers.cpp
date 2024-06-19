// Given an array A of integers and another number K. Find all the unique quadruple from the given array that sums up to K.

// Also note that all the quadruples which you return should be internally sorted, ie for any quadruple [q1, q2, q3, q4] the following should follow: q1 <= q2 <= q3 <= q4.

// Example 1:

// Input:
// N = 5, K = 3
// A[] = {0,0,2,1,1}
// Output: 0 0 1 2 
// Explanation: Sum of 0, 0, 1, 2 is equal
// to K.

// Example 2:

// Input:
// N = 7, K = 23
// A[] = {10,2,3,4,5,7,8}
// Output: 2 3 8 10 
//         2 4 7 10 
//         3 5 7 8 
// Explanation: Sum of 2, 3, 8, 10 = 23,
// sum of 2, 4, 7, 10 = 23 and sum of 3,
// 5, 7, 8 = 23.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function fourSum() which takes the array arr[] and the integer k as its input and returns an array containing all the quadruples in a lexicographical manner. In the output each quadruple is separate by $. The printing is done by the driver's code.

// Expected Time Complexity: O(N3).
// Expected Auxiliary Space: O(N2).

// Constraints:
// 1 <= N <= 100
// -1000 <= K <= 1000
// -100 <= A[] <= 100

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> answer;
        set<vector<int>> st;
        sort(arr.begin(), arr.end());
        int n=arr.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1, h=n-1;
                while(l<h){
                    int sum=arr[i]+arr[j]+arr[l]+arr[h];
                    if(sum == k){
                        vector<int> v={arr[i], arr[j], arr[l], arr[h]};
                        if(st.find(v) == st.end()){
                            st.insert(v);
                            answer.push_back(v);
                        }
                        l++; h--;
                    }else if(sum > k){
                        h--;
                    }else{
                        l++;
                    }
                }
            }
        }
        return answer;
    }
};