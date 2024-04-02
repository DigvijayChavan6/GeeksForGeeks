// Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.

// Example 1:

// Input:
// Input tree

// Output:
// 10
// Explanation:
// There are no two nodes whose absolute difference is smaller than 10.

// Example 2:

// Input:
// Input tree

// Output:
// 20
// Explanation:
// There are no two nodes whose absolute difference is smaller than 20.

// Your Task:
// You don't have to take any input. Just complete the function absolute_diff() , that takes root as input and return minimum absolute difference between any two nodes.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(Height of tree)

// Constraints:
// 2 <= n <= 105
// 1 <= Node->data <= 109

/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

};
*/

class Solution
{
public:
    void getDiff(Node *p, int &absDiff, Node *&prev)
    {
        if (!p)
            return;
        getDiff(p->left, absDiff, prev);
        if (prev)
        {
            absDiff = min(absDiff, abs(p->data - prev->data));
        }
        prev = p;
        getDiff(p->right, absDiff, prev);
    }
    int absolute_diff(Node *root)
    {
        // Your code here
        int absDiff = INT_MAX;
        Node *prev = NULL;
        getDiff(root, absDiff, prev);
        return absDiff;
    }
};