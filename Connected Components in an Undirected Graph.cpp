class Solution {
    void dfs(vector<int> &temp, int visited[], vector<vector<int>> &graph, int node){
        visited[node] = 1;
        temp.push_back(node);
        for(int next : graph[node]){
            if(visited[next] == 0){
                dfs(temp, visited, graph, next);
            }
        }
    }
    
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> graph(V);
        vector<vector<int>> answer;
        
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int visited[V] = {0};
        
        for(int i = 0; i < V; i++){
            if(visited[i] == 0){
                vector<int> temp;
                dfs(temp, visited, graph, i);
                answer.push_back(temp);
            }
        }
        
        return answer;
    }
};