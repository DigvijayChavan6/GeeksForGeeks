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
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        for(auto &e : edges){
            swap(e[1], e[2]);
            swap(e[1], e[0]);
        }
        sort(edges.begin(), edges.end());
        DSU d(V);
        
        int sum = 0;
        
        for(auto e : edges){
            int pu = d.find(e[1]);
            int pv = d.find(e[2]);
            
            if(pu != pv){
                sum += e[0];
                d.unite(e[1], e[2]);
            }
        }
        
        return sum;
    }
};














