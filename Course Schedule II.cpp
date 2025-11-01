class Solution {
  private:
  
    vector<int> bfs(int n, vector<vector<int>> &adj, vector<int> &indegree){
        vector<int> order;
        queue<int> q;
       
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
       
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            
            for(int val : adj[node]){
                indegree[val]--;
                if(indegree[val] == 0){
                    q.push(val);
                }
            }
        }
        
        
        
        return order.size() == n ? order : vector<int>{};
    }
    
  public:
    vector<int> findOrder(int n, vector<vector<int>> &pre) {
        // code here
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        
        for(int i = 0; i < pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
        
        return bfs(n, adj, indegree);
    }
};