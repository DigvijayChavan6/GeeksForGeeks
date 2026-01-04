// User function Template for C++
class DSU{
    public:
    vector<int> size;
    vector<int> parent;
    
    DSU(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    
    int find(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    
    void unite(int u, int v){
        int pu = find(u);
        int pv = find(v);
        
        if(pu == pv)return;
        
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};


class Solution {
  public:
    int largestIsland(vector<vector<int>>& grid) {
        // Your code goes here.
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        DSU ds(n*m);
        
        int nr[] = {1, 0, -1, 0};
        int nc[] = {0, 1, 0, -1};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int u = i * m + j;
                if(grid[i][j] == 1){
                    for(int p = 0; p < 4; p++){
                        int row = i + nr[p];
                        int col = j + nc[p];
                        if(row < n && row >= 0 && col < m && col >= 0 
                                    && grid[row][col] == 1){
                            int v = row * m + col;
                            ds.unite(u, v);
                        }
                    }
                    
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int u = i * m + j;
                if(grid[i][j] == 0){
                    set<int> temp;
                    for(int p = 0; p < 4; p++){
                        int row = i + nr[p];
                        int col = j + nc[p];
                        if(row < n && row >= 0 && col < m && col >= 0 
                                    && grid[row][col] == 1){
                            int v = row * m + col;
                            temp.insert(ds.find(v));
                        }
                    }
                    int sum = 0;
                    for(int par : temp){
                        sum += ds.size[par];
                    }
                    cnt = max(cnt, sum + 1);
                }else{
                    cnt = max(cnt, ds.size[ds.find(u)]);
                }
            }
        }
        
        return cnt;
    }
};