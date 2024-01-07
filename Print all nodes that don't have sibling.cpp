// Given a Binary Tree of size N, find all the nodes which don't have any sibling. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order.

// Two nodes are said to be siblings if they are present at the same level, and their parents are same.

// Note: Root node can not have a sibling so it cannot be included in our answer.

// Example 1:

// Input :
//        37
//       /   
//     20
//     /     
//   113 

// Output: 20 113
// Explanation: 20 and 113 dont have any siblings.

// Example 2:

// Input :
//        1
//       / \
//      2   3 

// Output: -1
// Explanation: Every node has a sibling.

// Your Task:  
// You dont need to read input or print anything. Complete the function noSibling() which takes the root of the tree as input parameter and returns a list of integers containing all the nodes that don't have a sibling in sorted order. If all nodes have a sibling, then the returning list should contain only one element -1.


// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(Height of the tree)


// Constraints:
// 1 ≤ N ≤ 10^4
// All nodes have distinct values.

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */



void get_sib(Node *p,vector<int>&vec){
    if(p==NULL)return;
    get_sib(p->left,vec);
    if(p->left==NULL&&p->right!=NULL)vec.push_back(p->right->data);
    else if(p->right==NULL&&p->left!=NULL)vec.push_back(p->left->data);
    get_sib(p->right,vec);
}

vector<int> noSibling(Node* node){
    vector<int>vec;
    get_sib(node,vec);
    if(vec.size()==0)vec.push_back(-1);
    sort(vec.begin(),vec.end());
    for(int i=1;i<vec.size();i++){
        if(vec[i-1]==vec[i]){
            vec.erase(vec.begin()+i);
            i--;
        }
    }
    return vec;
}