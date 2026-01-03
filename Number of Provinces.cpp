class Solution {
    
    int count = 1;
    
    void bfs (int src, vector<vector<int>> adj, int V, vector<bool> &visited){
        queue<int> q;
        
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;
            
            for(int i = 0; i < V; i++){
                if(adj[node][i] == 1 && visited[i] == false){
                    q.push(i);
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                count++;
                bfs(i, adj, V, visited);
            }
        }
        
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<bool> visited(V, false);
        bfs(0, adj, V, visited);
        return count;
    }
    
};





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
    
    void unio(int u, int v){
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
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DSU ob(V);
        
        for(int i = 0; i < V; i++){
            for( int j = 0; j < V; j++){
                if(adj[i][j] == 1){
                    ob.unio(i, j);
                }
            }
        }
        
        int cnt = 0;
        
        for(int i = 0; i < V; i++){
            if(ob.find(i) == i){
                cnt++;
            }
        }
        
        return cnt;
    }
};


