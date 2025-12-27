// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        if(start == end)return 0;
        
        vector<int> dist(100000, INT_MAX);
        queue<pair<int, int>> q;
        q.push({start, 0});
        
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            
            q.pop();
            
            for(int val : arr){
                int next = (val * node) % 100000;
                if(next == end)return d + 1;
                
                if(d + 1 < dist[next]){
                    q.push({next, d + 1});
                    dist[next] = d + 1;
                }
            }
        }
        
        return -1;
    }
};
