// Given a Binary Search Tree. The task is to find the minimum valued element in this given BST.

// Example 1:

// Input:
//            5
//          /    \
//         4      6
//        /        \
//       3          7
//      /
//     1
// Output: 1
// Example 2:

// Input:
//              9
//               \
//                10
//                 \
//                  11
// Output: 9
// Your Task:
// The task is to complete the function minValue() which takes root as the argument and returns the minimum element of BST. If the tree is empty, there is no minimum element, so return -1 in that case.

// Expected Time Complexity: O(Height of the BST)
// Expected Auxiliary Space: O(1).

// Constraints:
// 0 <= N <= 104

/*
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

void getNum(Node *p, int &val){
    if(p==NULL)return;
    getNum(p->left,val);
    if(val==-1)val=p->data;
    if(val!=-1)return;
    getNum(p->right,val);
}

int minValue(Node* root) {
    int val=-1;
    getNum(root,val);
    return val;
}
