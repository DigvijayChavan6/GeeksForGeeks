// Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. If K is already present in the BST, don't modify the BST.

// Example 1:

// Input:
//      2
//    /   \   
//   1     3
// K = 4
// Output: 
// 1 2 3 4
// Explanation: 
// After inserting the node 4
// Inorder traversal will be 1 2 3 4.
// Example 2:

// Input:
//         2
//       /   \
//      1     3
//              \
//               6
// K = 4
// Output: 
// 1 2 3 4 6
// Explanation: 
// After inserting the node 4
// Inorder traversal of the above tree will be 1 2 3 4 6.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function insert() which takes the root of the BST and Key K as input parameters and returns the root of the modified BST after inserting K. 
// Note: The generated output contains the inorder traversal of the modified tree.

// Expected Time Complexity: O(Height of the BST).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 <= Number of nodes initially in BST <= 105
// 1 <= K <= 109

/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    Node* insert(Node* n, int data) {
        struct Node *node=n,*i;
        i=(struct Node *)malloc(sizeof(struct Node));
        i->data=data;
        i->left=i->right=NULL;
        if(!n)return i;
        while(n){
            if(n->data<data){
                if(n->right==NULL){
                    n->right=i;
                    break;
                }
                n=n->right;
            }
            else if(n->data>data){
                if(n->left==NULL){
                    n->left=i;
                    break;
                }   
                n=n->left;
            }
            else return node;
        }
        return node;
    }
};