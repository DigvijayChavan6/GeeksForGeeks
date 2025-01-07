// You are given an array arr of integers and a list of queries. Each query consists of two indices, leftIndex and rightIndex, defining a range in the array. For each query, calculate the maximum prefix sum within the given range.

// A prefix sum is the sum of all elements from the start of the range up to a certain point within the range.

// Examples:

// Input: arr = [-1, 2, 3, -5], leftIndex = [0, 1], rightIndex = [3, 3]
// Output:[4, 5]
// Explanation:For the range [0, 3], the prefix sums are [-1, 1, 4, -1]. The maximum is 4. For the range [1, 3], the prefix sums are [2, 5, 0]. The maximum is 5.
// Input: arr = [1, -2, 3, 4, -5], leftIndex = [0, 2, 1], rightIndex = [4, 3, 3]
// Output: [6, 7, 5]
// Explanation: For the range [0, 4], the prefix sums are [1, -1, 2, 6, 1]. The maximum is 6. For the range [2, 3], the prefix sums are [3, 7]. The maximum is 7. For the range [1, 3], the prefix sums are [-2, 1, 5]. The maximum is 5.
// Expected Time Complexity: O(arr.size() * queries)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ arr.size() ≤ 10^6
// -10^4 ≤ arr[i] ≤ 10^4
// 1 ≤ queries ≤ 10^4
// 0 ≤ leftIndex[i] ≤ rightIndex[i] < arr.size()

class Solution {
    
    void build(vector<int> &seg, vector<int> &arr, int node, int l, int r) {
        if (l == r) {
            seg[node] = arr[l]; 
            return;
        }

        int mid = l + (r - l) / 2;
        build(seg, arr, 2 * node + 1, l, mid);
        build(seg, arr, 2 * node + 2, mid + 1, r);

        
        seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
    }
    
    int query(vector<int> &seg, int node, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) {
            return INT_MIN; 
        }

        if (l >= ql && r <= qr) {
            return seg[node];
        }

        int mid = l + (r - l) / 2;
        int left = query(seg, 2 * node + 1, l, mid, ql, qr);
        int right = query(seg, 2 * node + 2, mid + 1, r, ql, qr);

        return max(left, right); 
    }
    
  public:
    vector<int> maxPrefixes(vector<int>& arr, vector<int>& leftIndex,
                            vector<int>& rightIndex) {
        vector<int> prefix(arr.size(), 0);
        prefix[0] = arr[0];

        for (int i = 1; i < arr.size(); ++i) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        int n = arr.size();
        vector<int> seg(4 * n, 0);

        build(seg, prefix, 0, 0, n - 1);

        vector<int> result;

        for (int i = 0; i < leftIndex.size(); ++i) {
            int l = leftIndex[i];
            int r = rightIndex[i];

            if (l == 0) {
                result.push_back(query(seg, 0, 0, n - 1, l, r));
            } else {
                int maxPrefix = query(seg, 0, 0, n - 1, l, r);
                result.push_back(maxPrefix - prefix[l - 1]);
            }
        }

        return result;
    }
};
