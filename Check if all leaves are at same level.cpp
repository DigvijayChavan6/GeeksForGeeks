// Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. Return true if all leaf nodes are at the same level, and false otherwise.

// Example 1:

// Input:
// Tree:
//     1
//    / \
//   2   3
// Output:
// true
// Explanation:
// The binary tree has a height of 2 and the leaves are at the same level.
// Example 2:

// Input:
// Tree:
//     10
//    /  \
//  20   30
//  /  \
//  10   15
// Output:
// false
// Explanation:
// The binary tree has a height of 3 and the leaves are not at the same level.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(height of tree)

// Your Task:
// Implement the function check() that checks whether all the leaf nodes in the given binary tree are at the same level or not. The function takes the root node of the tree as an input and should return a boolean value (true/false) based on the condition.

// Constraints:
// 1 ≤ n ≤ 105

/* The structure of the binary tree is as follows
struct Node{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
  
    bool isSame(Node *p, int &height, int cnt){
        if(p == NULL)return true;
        cnt++;
        if(p->left == p->right){
            if(height == 0){
                height = cnt;
                return true;
            }
            return cnt == height;
        }
        return isSame(p->left,height,cnt) && isSame(p->right,height,cnt);
    }
    
    bool check(Node *root){
        int height=0;
        return isSame(root,height,0);
    }
    
};