// Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes at any level.
// For example, the maximum width of the following tree is 4 as there are 4 nodes at the 3rd level.

//           1
//        /     \
//      2        3
//    /    \    /    \
//   4    5   6    7
//     \
//       8

// Example 1:

// Input:
//        1
//      /    \
//     2      3
// Output: 2
// On the first level there is only
// one node 1
// On the second level there are
// two nodes 2, 3 clearly it is the 
// maximum number of nodes at any level

// Example 2:

// Input:
//         10
//       /     \
//     20      30
//    /    \
//   40    60
// Output: 2
// There is one node on level 1(10)
// There is two node on level 2(20, 30)
// There is two node on level 3(40, 60)
// Hence the answer is 2

// Your Task:
// You don't have to read any input. Complete the function getMaxWidth() that takes the node as a parameter and returns the maximum width. The driver code does the printing.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Width of the tree).

// Constraints:
// 1 <= Number of Nodes<= 105
// 0 <= nodes values <= 105
 

/*  Structure of a Binary Tree

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

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {
        stack<Node*> st, ts;
        int ans=INT_MIN;
        st.push(root);
        while(!st.empty()){
            ans=max(ans, (int) st.size());
            while(!st.empty()){
                Node *t=st.top();
                st.pop();
                if(t->left)ts.push(t->left);
                if(t->right)ts.push(t->right);
            }
            ans=max(ans, (int) ts.size());
            while(!ts.empty()){
                Node *t=ts.top();
                ts.pop();
                if(t->left)st.push(t->left);
                if(t->right)st.push(t->right);
            }
        }
        return ans;
        // Your code here
    }
};
