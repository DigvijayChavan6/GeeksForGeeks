class Solution {
    private:
    bool bfs(vector<int> &visited, int V, int node, int col, vector<vector<int>> &graph){
        queue<pair<int, int>> q;
        q.push({node, col});
        visited[node] = col;
        
        while(!q.empty()){
            int n = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int next : graph[n]){
                if(visited[next] == c){
                    return false;
                }else if(visited[next] == -1){
                    q.push({next, !c});
                    visited[next] = !c;
                }
            }
            
        }
        return true;   
    }
    
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        
        vector<int> visited(V, -1);
        
        vector<vector<int>> graph(V);
        
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        for(int i = 0; i < V; i++){
            if(visited[i] == -1){
                if(!bfs(visited, V, i, 0, graph)){
                    return false;
                }
            }
        }
        
        return true;
    }
};