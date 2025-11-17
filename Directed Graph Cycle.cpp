
class Solution {
    bool dfs(int node, vector<vector<int>> &grp, vector<int> &visited, vector<int> &path){
        visited[node] = 1;
        path[node] = 1;
        for(int next : grp[node]){
            if(visited[next] == -1){
                if(dfs(next, grp, visited, path)){
                    return true;
                }
            }else if(path[next] == 1){
                return true;
            }
        }
        path[node] = 0;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>> graph(V);
        vector<int> visited(V, -1);
        vector<int> path(V, -1);
        
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
        }
        
        for(int i = 0; i < V; i++){
            if(visited[i] == -1){
                if(dfs(i, graph, visited, path)){
                    return true;
                }
            }
        }
        
        return false;
    }
};