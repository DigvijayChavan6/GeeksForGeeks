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



class Solution {
    
    
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> graph(V);
        
        int indegree[V] = {0};
        
        for(auto edge : edges){
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> answer;
        while(!q.empty()){
            int node = q.front();
            answer.push_back(node);
            q.pop();
            
            for(int next : graph[node]){
                indegree[next]--;
                if(indegree[next] == 0){
                    q.push(next);
                }
            }
        }
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};