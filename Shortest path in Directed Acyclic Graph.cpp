// User function Template for C++
class Solution {
    void dfs(int node, stack<int> &st, vector<int> &vis, vector<vector<pair<int, int>>> &graph){
        vis[node] = 1;
        for(auto next : graph[node]){
            if(!vis[next.first]){
                dfs(next.first, st, vis, graph);
            }
        }
        
        st.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        int src = 0;
        
        vector<vector<pair<int, int>>> graph(V);
        
        for(auto edge : edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
        
        stack<int> st;
        vector<int> vis(V, 0);
        
        dfs(src, st, vis, graph);
        
        vector<int> dist(V, -1);
        dist[src] = 0;

        while(!st.empty()){
            int curr = st.top();
            st.pop();
            for(auto next : graph[curr]){
                if(dist[next.first] == -1){
                    dist[next.first] = dist[curr] + next.second;
                    continue;
                }
                dist[next.first] = min(dist[next.first], dist[curr] + next.second);
            }
        }
        
        return dist;
    }
};
