class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        int V = n;
        int src = 1;
        vector<int> dist(V+1, 1e8);
        vector<vector<pair<int, int>>> graph(V+1);
        priority_queue<pair<int, int>, vector<pair<int,  int>>, greater<pair<int, int>>> minHeap;
        vector<int> parent(V+1);
        
        for(int i = 1; i <= V; i++){
            parent[i] = i;
        }
        
        for(auto edge : edges){
            graph[edge[0]].push_back({edge[2], edge[1]});
            graph[edge[1]].push_back({edge[2], edge[0]});
        }
        
        minHeap.push({0, src});
        dist[src] = 0;
        
        while(!minHeap.empty()){
            int node = minHeap.top().second;
            int dt = minHeap.top().first;
            minHeap.pop();
            
            for(auto p : graph[node]){
                if(dist[p.second] > p.first + dt){
                    dist[p.second] = p.first + dt;
                    minHeap.push({dist[p.second], p.second});
                    parent[p.second] = node;
                }
            }
        }
        
        if(dist[V] == 1e8)return {-1};
        
        vector<int> path;
        int t = V;
        while(parent[t] != t){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(t);
        path.push_back(dist[V]);
        reverse(path.begin(), path.end());
        return path;
    }
};
