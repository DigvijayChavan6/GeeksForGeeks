// Given two binary trees with head reference as T and S having at most N nodes. The task is to check if S is present as subtree in T.
// A subtree of a tree T1 is a tree T2 consisting of a node in T1 and all of its descendants in T1.

// Example 1:

// Input:
// T:      1          S:   3
//       /   \            /
//      2     3          4
//    /  \    /
//   N    N  4
// Output: 1 
// Explanation: S is present in T

// Example 2:

// Input:
// T:      26         S:   26
//        /   \           /  \
//      10     N        10    N
//    /    \           /  \
//    20    30        20  30
//   /  \            /  \
//  40   60         40  60
// Output: 1 
// Explanation: 
// S and T are both same. Hence, 
// it can be said that S is a subtree 
// of T.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function isSubtree() that takes root node of S and T as parameters and returns 1 if S is a subtree of T else 0.

// Note: The nodes can have the duplicate values.


// Expected Time Complexity: O(N^2).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= Number of nodes <= 103
// 1 <= Value of nodes <= 104


/* A binary tree node

struct Node{
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
    void isSub(Node *p, string child, bool &result){
        if(p == NULL || result)return ;
        string s="";
        getString(p, s);
        if(s == child){
            result=true;
            return;
        }
        if(p->left)isSub(p->left, child, result);
        if(p->right)isSub(p->right, child, result);
    }
    void getString(Node *p, string &str){
        if(p == NULL)return ;
        getString(p->left, str);
        str+=to_string(p->data);
        getString(p->right, str);
    }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) {
        // Your code here
        bool result=false;
        string child="";
        getString(S, child);
        isSub(T, child, result);
        return result;
    }
};


class Solution{
    bool match(Node *T, Node *S){
        if(!T && !S)return true;
        if(!T && S || T && !S)return false;
        if(T->data != S->data)return false;
        return match(T->left, S->left) && match(T->right, S->right);
    }
  public:
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) {
        // Your code here
        if(!T)return false;
        if(T->data == S->data && match(T, S))return true;
        return isSubTree(T->left, S) || isSubTree(T->right, S);
    }
};