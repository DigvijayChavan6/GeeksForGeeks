class Solution {
    bool dfs(int node, int V, vector<vector<int>> &graph, vector<int> &visited, vector<int> &path,
    vector<int> &safe){
        visited[node] = 1;
        path[node] = 1;
        
        for(int next : graph[node]){
            if(visited[next] == 0){
                if(dfs(next, V, graph, visited, path, safe)){
                    return true;
                }
            }else if(path[next] == 1){
                return true;
            }
        }
        
        
        
        safe[node] = 1;
        path[node] = 0;
        return false;
    }
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> visited(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> safe(V, 0);
        vector<vector<int>> graph(V);
        
        for(auto v : edges){
            graph[v[0]].push_back(v[1]);
        }
        
        for(int i = 0; i < V; i++){
            if(visited[i] == 0){
                dfs(i, V, graph, visited, pathVis, safe);
            }
        }
        
        
        vector<int> safeNodes;
        
        for(int i = 0; i < V; i++){
            if(safe[i] == 1){
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};