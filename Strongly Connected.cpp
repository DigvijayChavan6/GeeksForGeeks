//Position this line where user code will be pasted.
class Solution {
    void dfs(int node, vector<int> &vis, stack<int> &st,vector<vector<int>> &adj){
        vis[node] = 1;
        for(int next : adj[node]){
            if(vis[next] == 0){
                dfs(next, vis, st, adj);
            }
        }
        st.push(node);
    }
    void dfs2(int node, vector<int> &vis, stack<int> &st,vector<vector<int>> &adj){
        vis[node] = 1;
        for(int next : adj[node]){
            if(vis[next] == 0){
                dfs(next, vis, st, adj);
            }
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        
        stack<int> st;
        vector<int> vis(n, 0);
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                dfs(i, vis, st, adj);
            }
        }
        
        vector<vector<int>> radj(n);
        
        for(int i = 0; i < n; i++){
            for(int j : adj[i]){
                radj[j].push_back(i);
            }
        }
        
        int cnt = 0;
        fill(vis.begin(), vis.end(), 0);
        while(!st.empty()){
            int i = st.top();
            st.pop();
            if(vis[i] == 0){
                dfs2(i, vis, st, radj);
                cnt++;
            }
        }
        
        
        return cnt;
    }
};







