// User function Template for C++
class DSU{
    vector<int> size;
    vector<int> parent;
    
    public:
    
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DSU ds(n*m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;
        int cnt = 0;
        
        int nr[] = {1, 0, -1, 0};
        int nc[] = {0, -1, 0, 1};
        
        for(auto it : operators){
            int r = it[0];
            int c = it[1];
            
            if(vis[r][c] == 1){
                ans.push_back(cnt);
                continue;
            }
            
            cnt++;
            vis[r][c] = 1;
            
            int u = r * m + c;
            
            for(int i = 0; i < 4; i++){
                int row = r + nr[i];
                int col = c + nc[i];
                
                if(row < n  && row >= 0 && col < m && col >= 0){
                    int v = row * m + col;
                    if(vis[row][col] == 1){
                        if(ds.find(u) != ds.find(v)){
                            cnt--;
                            ds.unite(u, v);
                        }
                    }
                }
            }
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
