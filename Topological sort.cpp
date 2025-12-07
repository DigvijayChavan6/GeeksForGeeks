// Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

// Example 1:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 3, 2, 1, 0.

// Example 2:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 5, 4, 2, 1, 3, 0.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

// Expected Time Complexity: O(V + E).
// Expected Auxiliary Space: O(V).

// Constraints:
// 2 ≤ V ≤ 104
// 1 ≤ E ≤ (N*(N-1))/2

class Solution{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
        vector<int> indegree(V, 0);
	    for(int i=0;i<V;i++){
	        for(int v : adj[i]){
	            indegree[v]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0)q.push(i);
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int n=q.front();
	        q.pop();
	        topo.push_back(n);
	        for(int v : adj[n]){
	            indegree[v]--;
	            if(indegree[v] == 0)q.push(v);
	        }
	    }
	    return topo;
	}
};


class Solution {
    void dfs(int node, int vis[], stack<int> &st, vector<vector<int>> graph){
        vis[node] = 1;
        
        for(int next : graph[node]){
            if(vis[next] == 0){
                dfs(next, vis, st, graph);
            }
        }
        
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> graph(V);
        
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
        }
        
        stack<int> st;
        vector<int> answer;
        
        int vis[V] = {0};
        
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                dfs(i, vis, st, graph);
            }
        }
        
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        
        return answer;
    }
};



class Solution {
    // void dfs(int node, int vis[], stack<int> &st, vector<vector<int>> &graph){
    //     vis[node] = 1;
        
    //     for(int next : graph[node]){
    //         if(vis[next] == 0){
    //             dfs(next, vis, st, graph);
    //         }
    //     }
        
    //     st.push(node);
    // }
    void bfs(queue<int> &q, vector<int> &answer, int indegree[], vector<vector<int>> &graph){
        int node = q.front();
        q.pop();
        answer.push_back(node);
        
        for(int next : graph[node]){
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> graph(V);
        int indegree[V] = {0};
        
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        vector<int> answer;
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
    
        while(!q.empty()){
            bfs(q, answer, indegree, graph);
        }
        
        return answer;
    }
};
