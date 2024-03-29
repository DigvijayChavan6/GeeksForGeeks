// Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

// Note: H is the height of the tree and this space is used implicitly for the recursion stack.
 

// TreeToList

// Example 1:

// Input:
//       1
//     /  \
//    3    2
// Output:
// 3 1 2 
// 2 1 3 
// Explanation: DLL would be 3<=>1<=>2
// Example 2:

// Input:
//        10
//       /   \
//      20   30
//    /   \
//   40   60
// Output:
// 40 20 60 10 30 
// 30 10 60 20 40
// Explanation:  DLL would be 
// 40<=>20<=>60<=>10<=>30.
// Your Task:
// You don't have to take input. Complete the function bToDLL() that takes root node of the tree as a parameter and returns the head of DLL . The driver code prints the DLL both ways.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(H).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 0 ≤ Data of a node ≤ 105

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

// This function should return head to the DLL
class Solution{
    public: 
    void doTask(Node *p, Node **prev, Node **start){
        if(p == NULL)return;
        if(p->left == p->right && *prev == NULL){
            *prev=p;
            *start=p;
            return;
        }
        doTask(p->left,prev,start);
        if(*prev != NULL)(*prev)->right=p;
        else *start=p;
        p->left=*prev;
        *prev=p;
        doTask(p->right,prev,start);
    }
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root){
        Node *prev=NULL,*start=NULL;
        doTask(root,&prev,&start);
        return start;
    }
};