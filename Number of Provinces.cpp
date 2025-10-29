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