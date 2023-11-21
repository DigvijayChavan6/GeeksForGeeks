// Given two binary trees, the task is to find if both of them are identical or not.
// Note: You need to return true or false, the printing is done by the driver code.

// Example 1:

// Input:
//      1          1
//    /   \      /   \
//   2     3    2     3
// Output: 
// Yes
// Explanation: 
// There are two trees both having 3 nodes and 2 edges, both trees are identical having the root as 1, left child of 1 is 2 and right child of 1 is 3.
// Example 2:

// Input:
//     1       1
//   /  \     /  \
//  2    3   3    2
// Output: 
// No
// Explanation: There are two trees both having 3 nodes and 2 edges, but both trees are not identical.
// Your task:
// Since this is a functional problem you don't have to worry about input, you just have to complete the function isIdentical() that takes two roots as parameters and returns true or false. The printing is done by the driver code.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).

// Constraints:
// 1 <= Number of nodes <= 105
// 1 <=Data of a node <= 109

struct Node
{
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
    //Function to check if two trees are identical.
    bool bl=true;
    void go(Node *p,Node *q){
        if(bl==false)return;
        if(((p==NULL) && (q!=NULL))||((q==NULL) && (p!=NULL))){
            bl=false;
            return;
        }
        if(p==q)return;
        if(p->data!=q->data){
            bl=false;
            return;
        }
        go(p->left,q->left);
        go(p->right,q->right);
    }
    bool isIdentical(Node *r1, Node *r2){
        go(r1,r2);
        return bl;
    }
};
