// Given a Binary Tree, your task is to find its level order traversal.
// For the below tree the output will be 1 $ 2 3 $ 4 5 6 7 $ 8 $.

// Return the level order traversal line by line.

//           1
//        /     \
//      2        3
//    /    \     /   \
//   4     5   6    7
//     \
//      8

// Example 1:

// Input:
//           1
//         /
//        4
//      /   \
//     4     2
// Output:1 $ 4 $ 4 2 $

// Example 2:

// Input:
//             10
//           /    \
//         20      30
//      /     \
//     40     60
// Output: 10 $ 20 30 $ 40 60 $
// Your Task:
// This is a function problem. You don't need to read input. Just complete the function levelOrder() that takes nodes as parameter and returns level order traversal as a 2D list.

// Note: The driver code prints the levels '$' separated.
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N).

// Constraints:
// 1 <= Number of edges <= 1000
// 0 <= Data of a node <= 100

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

void getData(Node *p, vector<vector<int>> &data){
    queue<Node*> s;
    s.push(p);
    while(!s.empty()){
        queue<Node*> st;
        swap(st,s);
        vector<int> temp;
        while(!st.empty()){
            Node *t=st.front();
            temp.push_back(t->data);
            if(t->left)s.push(t->left);
            if(t->right)s.push(t->right);
            st.pop();
        }
        data.push_back(temp);
    }
}

//Function to return the level order traversal line by line of a tree.
vector<vector<int>> levelOrder(Node* node){
  //Your code here
    vector<vector<int>> data;
    getData(node, data);
    return data;
}

