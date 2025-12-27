

class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> graph(V);
        
        for(int i = 0; i < edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        vector<vector<int>> dist(V, vector<int>(2, INT_MAX));
        
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;
        
        
        dist[0][0] = 0;
        dist[0][1] = 0;
        
        pq.push({0, 0});
        
        while(!pq.empty()){
            int dt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto next : graph[node]){
                if(dt + next.second < dist[next.first][0]){
                    dist[next.first][0] = dt + next.second;
                    dist[next.first][1] = 1;
                    pq.push({dist[next.first][0], next.first});
                }else if(dt + next.second == dist[next.first][0]){
                    dist[next.first][1] += 1;
                    pq.push({dist[next.first][0], next.first});
                }
            }
        }
        
        return dist[V-1][1];
    }
};