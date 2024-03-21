// Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

// Example 1:

// Input: 
//         4        
//        /  \       
//       2   5      
//      / \   /  \     
//     7  1 2  3    
//       /
//      6
// Output: 
// 13
// Explanation:
//         4        
//        /  \       
//       2   5      
//      / \   /  \     
//     7  1 2  3 
//       /
//      6
// The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13

// Example 2:

// Input: 
//           1
//         /   \
//        2    3
//       / \    /  \
//      4   5 6   7
// Output: 
// 11
// Explanation:
// Use path 1->3->7, with sum 11.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= n <= 105
// 0 <= data of each node <= 104

/*
structure of the node of the binary tree is as
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    void getSum(Node *p, int &mx_sum, int cur_sum, int &mx_hit, int cur_hit)
    {
        if (p == NULL)
            return;
        cur_hit++;
        cur_sum += p->data;
        if (p->left == p->right)
        {
            if (cur_hit > mx_hit)
            {
                mx_sum = cur_sum;
                mx_hit = cur_hit;
            }
            else if (cur_hit == mx_hit)
            {
                mx_sum = max(mx_sum, cur_sum);
            }
        }
        getSum(p->left, mx_sum, cur_sum, mx_hit, cur_hit);
        getSum(p->right, mx_sum, cur_sum, mx_hit, cur_hit);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int mx_sum = 0, cur_sum = 0, mx_hit = 0, cur_hit = 0;
        getSum(root, mx_sum, cur_sum, mx_hit, cur_hit);
        return mx_sum;
    }
};