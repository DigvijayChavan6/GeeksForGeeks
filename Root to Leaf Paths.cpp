// Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

// Example 1:

// Input:
//        1
//     /     \
//    2       3
// Output: 
// 1 2 
// 1 3 
// Explanation: 
// All possible paths:
// 1->2
// 1->3

// Example 2:

// Input:
//          10
//        /    \
//       20    30
//      /  \
//     40   60
// Output: 
// 10 20 40 
// 10 20 60 
// 10 30 

// Your Task:
// Your task is to complete the function Paths() which takes the root node as an argument and returns all the possible paths. (All the paths are printed in new lines by the driver's code.)

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(height of the tree)

// Constraints:
// 1<=n<=104

/*
Definition for Binary Tree Node
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void getPaths(Node *root, vector<int> path, vector<vector<int>> &allPaths){
        if(!root)return;
        path.push_back(root->data);
        if(root->left == root->right){
            allPaths.push_back(path);
        }
        getPaths(root->left, path, allPaths);
        getPaths(root->right, path, allPaths);
    }
    vector<vector<int>> Paths(Node* root) {
        vector<int> path;
        vector<vector<int>> allPaths;
        getPaths(root, path, allPaths);
        return allPaths;
    }
};
