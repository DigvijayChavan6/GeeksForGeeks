// Given a Linked List Representation of Complete Binary Tree. The task is to construct the Binary tree and print the level order traversal of the Binary tree. 
// Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.

// Examples:

// Input: n = 5, k = 1->2->3->4->5
// Output: 1 2 3 4 5
// Explanation: The tree would look like
//       1
//     /   \
//    2     3
//  /  \
// 4   5
// Now, the level order traversal of
// the above tree is 1 2 3 4 5.

// Input: n = 5, k = 5->4->3->2->1
// Output: 5 4 3 2 1
// Explanation: The tree would look like
//      5
//    /  \
//   4    3
//  / \
// 2   1
// Now, the level order traversal of
// the above tree is 5 4 3 2 1.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).
// Constraints:
// 1 <= n <= 105
// 1 <= ki <= 105

/*
The structure of Link list Node is as follows
struct Node{
    int data;
    struct node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
The structure of TreeNode is as follows
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
};
*/

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    // Your code here
    queue<TreeNode*> q, p, e;
    root=new TreeNode(head->data);
    q.push(root);
    while(!q.empty() || !p.empty()){
        while(!q.empty()){
            TreeNode *rt=q.front(), *l, *r;
            q.pop();
            if(head->next){
                head=head->next;
                l=new TreeNode(head->data);
                rt->left=l;
                p.push(l);
                if(head->next){
                    head=head->next;
                    r=new TreeNode(head->data);
                    rt->right=r;
                    p.push(r);
                }
            }
        }
        q=p;
        p=e;
    }
}