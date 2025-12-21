// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dest) {
        // code here
        
        if(src == dest)return 0;
        
        queue<pair<int, int>> q;
        q.push(src);
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e8));
        dist[src.first][src.second] = 0;
        
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            int rw[] = { 0, 1, 0, -1};
            int cl[] = {1, 0, -1, 0};
            
            for(int i = 0; i < 4; i++){
                int row = rw[i] + r;
                int col = cl[i] + c;
                
                if(row >= 0 && row < n && col < m && col >= 0){
                    if(grid[row][col] && dist[r][c] + 1 < dist[row][col]){
                        dist[row][col] = dist[r][c] + 1;
                        if(row == dest.first && col == dest.second) return dist[row][col];
                        q.push({row, col});
                    }
                }
            }
            grid[r][c] = 0;
        }
        
        
        return -1;
    }
};
