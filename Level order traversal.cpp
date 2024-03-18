// Given a root of a binary tree with n nodes, find its level order traversal.
// Level order traversal of a tree is breadth-first traversal for the tree.

// Example 1:

// Input:
//     1
//   /   \ 
//  3     2
// Output:
// 1 3 2
// Example 2:

// Input:
//         10
//      /      \
//     20       30
//   /   \
//  40   60
// Output:
// 10 20 30 40 60
// Your Task:
// You don't have to take any input. Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n ≤ 105
// 0 ≤ Data of a node ≤ 109

/* A binary tree Node

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


class Solution{
    public:
    void bft(vector<int> &vec, Node *p){
        queue<Node*> q;
        q.push(p);
        while(!q.empty()){
            Node *n=q.front();
            if(n != NULL){
                vec.push_back(n->data);
                q.push(n->left);
                q.push(n->right);
                q.pop();
            }
            else{
                q.pop();
            }
        }
    }
    vector<int> levelOrder(Node* root){
        vector<int> vec;
        bft(vec, root);
        return vec;
    }
};