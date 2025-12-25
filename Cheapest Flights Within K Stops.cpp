


class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Code here
        
        vector<vector<pair<int, int>>> graph(n);
        
        for(int i = 0; i < flights.size(); i++){
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        
        queue<pair<int, int>> q;
        vector<int> dist(n, INT_MAX);
        
        q.push({src, 0});
        dist[src] = 0;
        
        while(K >= 0 && !q.empty()){
            int cnt = q.size();
            
            while(cnt--){
                int node = q.front().first;
                int d = q.front().second;
                for(auto p : graph[node]){
                    if(d + p.second < dist[p.first]){
                        dist[p.first] = d + p.second;
                        q.push({p.first, dist[p.first]});
                    }   
                }
                q.pop();
            }
            K--;
        }
        
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};