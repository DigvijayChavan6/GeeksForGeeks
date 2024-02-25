// Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
//  Example 1:

// Input:
//       1
//     /   \
//    2     3
// Output: 
// 1 2 3
// Explanation:
// The converted BST will be 
//       2
//     /   \
//    1     3

// Example 2:

// Input:
//           1
//        /    \
//      2       3
//    /        
//  4       
// Output: 
// 1 2 3 4
// Explanation:
// The converted BST will be

//         3
//       /   \
//     2     4
//   /
//  1
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST. The driver code will print inorder traversal of the converted BST.

// Expected Time Complexity: O(NLogN).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= Number of nodes <= 105

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    void makeBst(Node *p, vector<int> &vec, int &i){
        if(p == NULL)return ;
        makeBst(p->left, vec, i);
        p->data = vec[i++];
        makeBst(p->right, vec, i);
    }
    void getData(Node *p, vector<int> &vec){
        if(p == NULL)return ;
        getData(p->left, vec);
        vec.push_back(p->data);
        getData(p->right, vec);
    }
    Node *binaryTreeToBST (Node *root){
        int pos=0;
        vector<int> vec;
        getData(root, vec);
        sort(vec.begin(), vec.end());
        makeBst(root, vec, pos);
        return root;
    }
};