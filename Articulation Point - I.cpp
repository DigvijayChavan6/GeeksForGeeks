// User function Template for C++

class Solution {
    int timer = 1;
    void dfs(int node, int parent, vector<int> &ts, vector<int> &lw, vector<int> &mark, 
            vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        ts[node] = lw[node] = timer++;
        int cnt = 0;
        for(int next : adj[node]){
            if(next == parent)continue;
            if(vis[next] == 0){
                dfs(next, node, ts, lw, mark, adj, vis);
                lw[node] = min(lw[node], lw[next]);
                if(lw[next] >= ts[node] && parent != -1){
                    mark[node] = 1;
                }
                cnt++;
            }else{
                lw[node] = min(lw[node], ts[next]);
            }
        }
        if(cnt > 1 && parent == -1){
            mark[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<int> mark(V, 0);
        vector<int> vis(V, 0);
        vector<int> ts(V, 0);
        vector<int> lw(V, 0);
        
        dfs(0, -1, ts, lw, mark, adj, vis);
        
        for(int i = 0; i < V; i++){
            if(mark[i]){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0)return {-1};
        return ans;
    }
};