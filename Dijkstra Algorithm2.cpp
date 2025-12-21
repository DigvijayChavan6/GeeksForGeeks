class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        vector<vector<pair<int, int>>> graph(V);
        priority_queue<pair<int, int>, vector<pair<int,  int>>, greater<pair<int, int>>> minHeap;
        
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
                }
            }
        }
        
        return dist;
    }
};