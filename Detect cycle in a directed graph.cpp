// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


// Example 1:

// Input:



// Output: 1
// Explanation: 3 -> 3 is a cycle


// Example 2:

// Input:


// Output: 0
// Explanation: no cycle in the graph


// Your task:
// You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
// In the adjacency list adj, element adj[i][j] represents an edge from i to j.


// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)


// Constraints:
// 1 ≤ V, E ≤ 105

class Solution {
  public:
    bool checkFor(int i, vector<int> &visited, vector<int> &currCycle, vector<int> adj[]){
        currCycle[i]=true;
        for(int ad : adj[i]){
            if(visited[ad]){
                if(currCycle[ad])return true;
            }else{
                visited[ad]=true;
                if(checkFor(ad, visited, currCycle, adj)){
                    return true;
                }
            }
        }
        currCycle[i]=false;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V, false);
        vector<int> currCycle(V, false);
        for(int i=0;i<V;i++){
            visited[i]=true;
            if(checkFor(i, visited, currCycle, adj))return true;
        }
        return false;
    }
};