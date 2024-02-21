// You are given two arrays of size n1 and n2. Your task is to find all the elements that are common to both the arrays and sum them. If there are no common elements the output would be 0.

// Note: The arrays may contain duplicate elements. However, you need to sum only unique elements that are common to both arrays and answer may be too large so return it with modulo (109+7) .

 

// Example1:

// Input:
// 5 6
// 1 2 3 4 5
// 2 3 4 5 6 7
// Output: 14
// Explanation: Common unique elements in both arrays are 2, 3, 4 and 5 so answer will be 2+3+4+5 = 14
// Example2:

// Input:
// 5 6
// 1 2 2 3 5
// 3 3 2 2 6 5
// Output: 10
// Explanation: Common unique elements in both arrays are 2, 3 and 5 so answer will be 2+3+5 = 10
// Your Task:
// Since this is a function problem, you don't need to take any input. Just complete the provided function commonSum which takes two integer n1 , n2 and two integer arrays arr1 and arr2 have sizes n1 and n2 respectively.

// Expected Time Complexity : O(n1 + n2)

// Expected Space Complexity : O(min(n1,n2))

// Constraints:
// 1 <= n1,n2 <= 106
// 1 <= arr1[i] , arr2[i] <= 109

class Solution {
  public:
    int commonSum(int n1, int n2, vector<int> &arr1, vector<int> &arr2) {
        set<long long> st;
        long long int sum=0;
        for(int i=0;i<n1;i++){
            st.insert(arr1[i]);
        }
        for(int i=0;i<n2;i++){
            if(st.find(arr2[i]) != st.end()){
                sum=(sum+arr2[i])%1000000007;
                st.erase(arr2[i]);
            }
        }
        return sum;
    }
};