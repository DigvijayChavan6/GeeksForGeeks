class Solution {
public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> lis;
        vector<int> dp(n, 1), parent(n, -1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }
        
        int maxLen = 0, ind = 0;
        
        for(int i = 0; i < n; i++){
            if(maxLen < dp[i]){
                maxLen = dp[i];
                ind = i;
            }
        }
        
        while(ind != -1){
            lis.push_back(arr[ind]);
            ind = parent[ind];
        }
        
        reverse(lis.begin(), lis.end());
        
        return lis;
    }
};

//         vector<int> temp;
//         vector<int> index;
//         vector<int> parent(n, -1);

//         for(int i = 0; i < n; i++) {
//             int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();

//             if(ind == temp.size()) {
//                 temp.push_back(arr[i]);
//                 index.push_back(i);

//                 if(ind > 0)
//                     parent[i] = index[ind - 1];
//             } 
//             else {
//                 if(arr[i] < temp[ind] || (arr[i] == temp[ind] && i < index[ind])) {
//                     temp[ind] = arr[i];
//                     index[ind] = i;

//                     if(ind > 0)
//                         parent[i] = index[ind - 1];
//                 }
               
//             }
//         }

//         // reconstruct
//         vector<int> lis;
//         int t = index.back();

//         while(t != -1) {
//             lis.push_back(arr[t]);
//             t = parent[t];
//         }

//         reverse(lis.begin(), lis.end());
//         return lis;
//     }
// };