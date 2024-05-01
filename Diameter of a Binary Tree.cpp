// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes. The diagram below shows two trees each with diameter nine, the leaves that form the ends of the longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes). 

// Example 1:

// Input:
//        1
//      /  \
//     2    3
// Output: 3

// Example 2:

// Input:
//          10
//         /   \
//       20    30
//     /   \ 
//    40   60
// Output: 4

// Your Task:
// You need to complete the function diameter() that takes root as parameter and returns the diameter.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= Number of nodes <= 10000
// 1 <= Data of a node <= 1000

 
/* Tree node structure  used in the program

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    void setOne(Node *root){
        if(!root)return ;
        if(root->left == root->right)root->data=1;
        setOne(root->left);
        setOne(root->right);
    }
    void setMax(Node *root, int &answer){
        if(!root)return ;
        setMax(root->left, answer);
        setMax(root->right, answer);
        int lft=0, rgt=0;
        if(root->left)lft=root->left->data;
        if(root->right)rgt=root->right->data;
        root->data=max(lft, rgt)+ 1;
        answer=max(answer, lft+rgt+1);
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        setOne(root);
        int answer=INT_MIN;
        setMax(root, answer);
        return answer;
    }
};
