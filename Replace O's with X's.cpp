class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j == 0 || i == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 'O'){
                        q.push({i, j});
                        grid[i][j] = 'T';
                    }
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int r[] = {1, 0, -1, 0};
            int c[] = {0, -1, 0, 1};
            
            for(int i = 0; i < 4; i++){
                int a = row + r[i];
                int b = col + c[i];
                if(a >= 0 && b >= 0 && a < n && b < m && grid[a][b] == 'O'){
                    q.push({a, b});
                    grid[a][b] = 'T';
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'O'){
                    grid[i][j] = 'X';
                }
                if(grid[i][j] == 'T'){
                    grid[i][j] = 'O';
                }
            }
        }
        
    }
};