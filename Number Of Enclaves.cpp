class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        vector<vector<int>> grp = grid;
        queue<pair<int, int>> q;
        
        int n = grp.size();
        int m = grp[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && grp[i][j] == 1){
                    q.push({i, j});
                    grp[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            int r[] = {0, 1, 0, -1};
            int c[] = {1, 0, -1, 0};
            
            for(int i = 0; i < 4; i++){
                int a = row + r[i];
                int b = col + c[i];
                
                if(a < n && a >= 0 && b < m && b >= 0 && grp[a][b] == 1){
                    q.push({a, b});
                    grp[a][b] = 0;
                }
            }
        }
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grp[i][j] == 1){
                    ++cnt;
                }
            }
        }
        
        return cnt;
    }
};