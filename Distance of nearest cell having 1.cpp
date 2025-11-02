class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 0));
        vector<vector<int>> visited = distance;
        
        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                    distance[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            
            q.pop();
            
            int a[] = {0, 1, 0, -1};
            int b[] = {-1, 0, 1, 0};
            
            
            for(int i = 0; i < 4; i++){
                int row = r+a[i];
                int col = c+b[i];
                if(row >= 0 && row < n && col >= 0 && col < m){
                    if(visited[row][col] == 0){
                        q.push({{row, col}, d+1});
                        visited[row][col] = 1;
                        distance[row][col] = d+1;
                    }
                }
            }
        }
        
        
        return distance;
    }
};