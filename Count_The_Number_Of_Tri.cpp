class Solution {
  public:
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        sort(arr.begin(), arr.end());

        for (int i = n - 1; i >= 2; --i) {
            int l = 0, h = i - 1;
            while (l < h) {
                if (arr[l] + arr[h] > arr[i]) {
                    ans += (h - l);
                    --h;
                } else {
                    ++l;
                }
            }
        }

        return ans;
    }
};
