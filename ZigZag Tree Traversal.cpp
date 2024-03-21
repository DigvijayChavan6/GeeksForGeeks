// Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.

// Example 1:

// Input:
//         1
//       /   \
//      2    3
//     / \    /   \
//    4   5 6   7
// Output:
// 1 3 2 4 5 6 7

// Example 2:

// Input:
//            7
//         /     \
//        9      7
//      /  \      /   
//     8   8  6     
//    /  \
//   10  9 
// Output:
// 7 7 9 8 8 6 9 10 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the zig-zag level-order traversal of the tree.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).

// Constraints:
// 1 <= n <= 105

/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    void getZig(Node *p, vector<int> &zig)
    {
        stack<Node *> left, right;
        left.push(p);
        while (!left.empty() || !right.empty())
        {
            Node *temp;
            while (!left.empty())
            {
                temp = left.top();
                zig.push_back(temp->data);
                if (temp->left)
                    right.push(temp->left);
                if (temp->right)
                    right.push(temp->right);
                left.pop();
            }
            while (!right.empty())
            {
                temp = right.top();
                zig.push_back(temp->data);
                if (temp->right)
                    left.push(temp->right);
                if (temp->left)
                    left.push(temp->left);
                right.pop();
            }
        }
    }
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> zig;
        getZig(root, zig);
        return zig;
    }
};
