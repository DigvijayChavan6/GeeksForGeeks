// Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

//     serialize() : stores the tree into an array a and returns the array.
//     deSerialize() : deserializes the array to the tree and returns the root of the tree.

// Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

// Example 1:

// Input:
//       1
//     /   \
//    2     3
// Output: 
// 2 1 3

// Example 2:

// Input:
//          10
//        /    \
//       20    30
//     /   \
//    40  60
// Output: 
// 40 20 60 10 30

// Your Task:
// The task is to complete two functions serialize which takes the root node of the tree as input and stores the tree into an array and deSerialize which deserializes the array to the original tree and returns the root of it.

// Expected Time Complexity: O(Number of nodes).
// Expected Auxiliary Space: O(Number of nodes).

// Constraints:
// 1 <= Number of nodes <= 104
// 1 <= Data of a node <= 109

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node{
    int data;
    Node* left;
    Node* right;
}; */


class Solution{
    public:
    void getArray(Node *root, vector<int> &data){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.front();
            q.pop();
            if(!node){
                data.push_back(-1);
                continue;
            }
            data.push_back(node->data);
            q.push(node->left);
            q.push(node->right);
        }
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        //Your code here
        vector<int> data;
        getArray(root, data);
        return data;
    }
    
    void getRoot(vector<int> A, Node *root){
        int size=A.size(), i=1;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            root=q.front();
            q.pop();
            if(A[i] == -1)root->left=NULL;
            else{
                root->left=new Node(A[i]);
                q.push(root->left);
            }
            i++;
            if(A[i] == -1)root->right=NULL;
            else{
                root->right=new Node(A[i]);
                q.push(root->right);
            }
            i++;
        }
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A){
       //Your code here
       Node *root=new Node(A[0]);
       getRoot(A, root);
       return root;
    }
};