

class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while(!pq.empty()){
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            int a[] = {1, 0, -1, 0};
            int b[] = {0, 1, 0, -1};
            
            for(int i = 0; i < 4; i++){
                int nr = a[i] + r;
                int nc = b[i] + c;
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int dif = abs(mat[r][c] - mat[nr][nc]);
                    
                    dif = max(dif, d);
                    
                    if(dist[nr][nc] > dif){
                        dist[nr][nc] = dif;
                        pq.push({dif, {nr, nc}});
                    }
                }
            }
        }
        
        
        return dist[n-1][m-1];
    }
};










