// Given a binary tree and the task is to find the spiral order traversal of the tree.

// Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right. 

// For below tree, function should return 1, 2, 3, 4, 5, 6, 7.


 
 

// Example 1:

// Input:
//       1
//     /   \
//    3     2
// Output:1 3 2

// Example 2:

// Input:
//            10
//          /     \
//         20     30
//       /    \
//     40     60
// Output: 10 20 30 60 40 

// Your Task:
// The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. The newline is automatically appended by the driver code.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= Number of nodes <= 105
// 0 <= Data of a node <= 105

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.

void getSpiral(vector<int> &vec, Node *p)
{
    stack<Node *> r, l;
    r.push(p);
    while (!r.empty() || !l.empty())
    {
        while (!r.empty())
        {
            struct Node *t = r.top();
            vec.push_back(t->data);
            if (t->right != NULL)
                l.push(t->right);
            if (t->left != NULL)
                l.push(t->left);
            r.pop();
        }
        while (!l.empty())
        {
            struct Node *t = l.top();
            vec.push_back(t->data);
            if (t->left != NULL)
                r.push(t->left);
            if (t->right != NULL)
                r.push(t->right);
            l.pop();
        }
    }
}

vector<int> findSpiral(Node *root)
{
    vector<int> vec;
    getSpiral(vec, root);
    return vec;
}
