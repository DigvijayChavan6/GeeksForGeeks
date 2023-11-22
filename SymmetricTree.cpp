// Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

// Example 1:

// Input:
//          5
//        /   \
//       1     1
//      /       \
//     2         2
// Output: 
// True
// Explanation: 
// Tree is mirror image of itself i.e. tree is symmetric
// Example 2:

// Input:
//          5
//        /   \
//       10     10
//      /  \     \
//     20  20     30
// Output: 
// False
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isSymmetric() which takes the root of the Binary Tree as its input and returns True if the given Binary Tree is the same as the Mirror image of itself. Else, it returns False.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 0<=N<=105

class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool truth=true;
    void mirror(struct Node *l,struct Node *r){
        if(l==NULL && r==NULL || !truth)return;
        if((l==NULL && r!=NULL)||(l!=NULL && r==NULL)||(r->data != l->data)){
            truth=false;
            return;
        }
        mirror(l->left,r->right);
        mirror(r->left,l->right);
    }
    bool isSymmetric(struct Node* root){
	    mirror(root,root);
	    return truth;
    }
};
