class Solution {
    
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        
        unordered_map<int, int> mp;
        
        vector<vector<int>> graph(V);
        
        for(auto edge : edges){
            if((edge[0] == c && edge[1] == d) || (edge[0] == d && edge[1] == c)){
                continue;
            }
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(V, false);
        
        queue<int> q;
        q.push(c);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;
            mp[node]++;
            
            for(int v : graph[node]){
                if(!visited[v]){
                    q.push(v);
                }
            }
        }
        
        q.push(d);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            visited[node] = true;
            
            if(mp[node])return false;
            
            for(int v : graph[node]){
                if(!visited[v]){
                    q.push(v);
                }
            }
        }
        
        return true;
    }
};