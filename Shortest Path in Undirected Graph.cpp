

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int> dist(V, -1);
        vector<vector<int>> graph(V);
        
        for(auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(src);
        
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            visited[node] = true;
            q.pop();
            
            for(int next : graph[node]){
                if(visited[next])continue;
                if(dist[next] == -1){
                    dist[next] = 1 + dist[node];
                }else{
                    dist[next] = min(dist[next], 1 + dist[node]);
                }
                q.push(next);
            }
        }
        
        return dist;
    }
};
