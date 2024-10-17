class Solution{
    // int store[100001];
    // int getMax(int arr[], int n, int i){
    //     if(i >= n)return 0;
    //     if(store[i])return store[i];
    //     int steal = arr[i] + getMax(arr, n, i+2);
    //     int skip = getMax(arr, n, i+1);
    //     return store[i]=max(steal, skip);
    // }
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n){
        // Your code here
    
        int ans = arr[0], a = ans, b = 0;
        for(int i=2; i<=n; ++i){
            int skip = a;
            int steal = arr[i-1] + b;
            ans = max(skip, steal);
            b = a;
            a = ans;
        }
        return ans;
    }
        // memset(store, 0, sizeof(store));
        // return getMax(arr, n, 0);
    
};