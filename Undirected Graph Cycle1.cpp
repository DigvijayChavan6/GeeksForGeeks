class Solution {
    
    bool bfs(int V, int src, vector<vector<int>> &graph, vector<bool> &visited){
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = true;
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int next : graph[node]){
                if(!visited[next]){
                    q.push({next, node});
                    visited[next] = true;
                }else{
                    if(next != parent){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<vector<int>> graph(V);
        
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(V, false);
        
        for(int i = 0; i < V; i++){
            if(!visited[i] && bfs(V, i, graph, visited)){
                return true;
            }
        }
        
        return false;
    }
};