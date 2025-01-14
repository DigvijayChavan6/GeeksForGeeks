// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.

// NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].

// Examples:

// Input: adj = [[1], [0,2,4], [1,3], [2,4], [1,3]] 
// Output: 1
// Explanation: 

// 1->2->3->4->1 is a cycle.
// Input: adj = [[], [2], [1,3], [2]]
// Output: 0
// Explanation: 

// No cycle in the graph.
// Constraints:
// 1 ≤ adj.size() ≤ 105

class Solution {
    bool dfs(int node, int parent, vector<bool>& v, vector<vector<int>>& adj){
        v[node] = true;
        for(int a : adj[node]){
            if(v[a]){
                if(a != parent){
                    return true;
                }
            }else{
                if(dfs(a, node, v, adj)){
                    return true;
                }
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        vector<bool> v(adj.size(), false);
        stack<int> st;
       
        
        for(int i = 0; i < adj.size(); i++){
            if(!v[i]){
                if(dfs(i, -1, v, adj)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
