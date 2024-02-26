// Given a Binary Tree of size N, your task is to complete the function countNonLeafNodes(), that should return the count of all the non-leaf nodes of the given binary tree.

// Example:

// Input: 
// Image
// Output:
// 2
// Explanation:
// Nodes 1 and 2 are the only non leaf nodes.
// Your Task:
// You don't need to take input or print anything. Your task is to complete the function countNonLeafNodes() that takes root as input and returns the number of non leaf nodes in the tree.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 ≤ Number of nodes ≤ 105


/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// you are required to complete this function
// the function should return the count of Non-Leaf Nodes
class Solution {
  public:
    void getCnt(Node *p, int &cnt){
        if(p == NULL)return ;
        if(p->left != p->right)cnt++;
        getCnt(p->left, cnt);
        getCnt(p->right, cnt);
    }
    int countNonLeafNodes(Node* root) {
        int cnt = 0;
        getCnt(root, cnt);
        return cnt;
    }
};