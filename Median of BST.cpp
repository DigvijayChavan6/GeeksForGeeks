// Given a Binary Search Tree of size N, find the Median of its Node values.

// Example 1:

// Input:
//        6
//      /   \
//    3      8   
//  /  \    /  \
// 1    4  7    9
// Output: 6
// Explanation: Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8, 9. So, here median will 6.


// Example 2:

// Input:
//        6
//      /   \
//    3      8   
//  /   \    /   
// 1    4   7   
// Output: 5
// Explanation:Inorder of Given BST will be:
// 1, 3, 4, 6, 7, 8. So, here median will
// (4 + 6)/2 = 10/2 = 5.

 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function findMedian() which takes the root of the Binary Search Tree as input and returns the Median of Node values in the given BST.
// Median of the BST is:

//     If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
//     If number of nodes are odd : then median = (N+1)/2th node.


// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the Tree).


// Constraints:
// 1<=N<=10000

/*
Structure of the binary Search Tree is as
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
// your task is to complete the Function
// Function should return median of the BST
int getCount(struct Node *p)
{
    if (p == NULL)
        return 0;
    if (p->left == p->right)
        return 1;
    return 1 + getCount(p->left) + getCount(p->right);
}
void getMed(struct Node *p, int &a, int &b, float &aa, float &bb)
{
    if (p == NULL)
        return;
    getMed(p->left, a, b, aa, bb);
    a--;
    b--;
    if (a == 0)
        aa = p->data;
    if (b == 0)
        bb = p->data;
    getMed(p->right, a, b, aa, bb);
}
float findMedian(struct Node *root)
{
    int n = getCount(root);
    int a = (n / 2), b = a + 1;
    if (n % 2 == 1)
        a = b;
    float aa = 0, bb = 0;
    getMed(root, a, b, aa, bb);
    return (aa + bb) / 2.0;
}
