// Given a binary tree and an integer target, check whether there is a root-to-leaf path with its sum as target.

// Examples :

// Input: tree = 1, target = 2
//             /   \
//           2     3
// Output: false
// Explanation: There is no root to leaf path with sum 2.
// Input: tree = 1,  target = 4
//             /   \
//           2     3
// Output: true
// Explanation: The sum of path from leaf node 3 to root 1 is 4.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(height of tree)

// Constraints:
// 1 ≤ number of nodes ≤ 104
// 1 ≤ target ≤ 106


/* A binary tree node
struct Node{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
    void checkForSum(Node *root, int t, bool &a){
        if(!root)return;
        t-=root->data;
        if(root->left == root->right && t == 0)a=true;
        checkForSum(root->left, t, a);
        checkForSum(root->right, t, a);
    }
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        bool answer=false;
        checkForSum(root, target, answer);
        return answer;
    }
};