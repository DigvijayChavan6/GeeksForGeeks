// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

// Example 1:

// Input:
//         1 
//       /   \
//      2     3  
//     / \   / \ 
//    4   5 6   7
//       / \
//      8   9
   
// Output: 1 2 4 8 9 6 7 3
// Explanation:


 

// Example 2:

// Input:
//             1
//            /
//           2
//         /  \
//        4    9
//      /  \    \
//     6    5    3
//              /  \
//             7     8

// Output: 1 2 4 6 5 7 8
// Explanation:

// As you can see we have not taken the right subtree. 
// Your Task:
// This is a function problem. You don't have to take input. Just complete the function boundary() that takes the root node as input and returns an array containing the boundary values in anti-clockwise.

// Expected Time Complexity: O(N). 
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 105

/* A binary tree Node
struct Node{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void left(Node *root, vector<int> &vec){
        if(root == NULL)return;
        if(root->left == root->right)return;
        vec.push_back(root->data);
        left(root->left,vec);
        if(root->left == NULL)left(root->right,vec);
    }
    void leaf(Node *root, vector<int> &vec){
        if(root == NULL)return;
        if(root->left == root->right)vec.push_back(root->data);
        leaf(root->left,vec);
        leaf(root->right,vec);
    }
    void right(Node *root, vector<int> &vec){
        if(root == NULL)return;
        if(root->left == root->right)return;
        right(root->right,vec);
        if(root->right == NULL)right(root->left,vec);
        vec.push_back(root->data);
    }
    vector<int> boundary(Node *root){
        vector<int> vec;
        vec.push_back(root->data);
        left(root->left,vec);
        if(root->left != root->right)leaf(root,vec);
        right(root->right,vec);
        return vec;
    }
};