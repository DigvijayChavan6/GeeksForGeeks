class Solution {

  private:
    int n, m;
    void bfs(int r, int c, set<vector<pair<int, int>>> &s, vector<vector<int>> &grp){
        queue<pair<int,int>> q;
        vector<pair<int, int>> t;
        q.push({r, c});
        t.push_back({r-r, c-c});
        grp[r][c] = 0;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            int a[] = {1, 0, -1, 0};
            int b[] = {0, 1, 0, -1};
            
            for(int i = 0; i < 4; i++){
                int rw = a[i] + row;
                int cl = b[i] + col;
                
                if((rw >= 0 && rw < n && cl >= 0 && cl < m) && grp[rw][cl] == 1){
                    q.push({rw, cl});
                    t.push_back({r-rw, c-cl});
                    grp[rw][cl] = 0;
                }
            }
        }
        s.insert(t);
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        vector<vector<int>> grp = grid;
        set<vector<pair<int, int>>> s;
        
        n = grp.size();
        m = grp[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grp[i][j] == 1){
                    bfs(i, j, s, grp);
                }
            }
        }
        return s.size();
    }
};