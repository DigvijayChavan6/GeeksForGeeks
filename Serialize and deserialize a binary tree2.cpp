// Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

// serialize() : stores the tree into an array a and returns the array.
// deSerialize() : deserializes the array to the tree and returns the root of the tree.
// Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

// Examples :

// Input: root = [1, 2, 3]
      
// Output: [2, 1, 3]
// Input: root = [10, 20, 30, 40, 60, N, N]
      
// Output: [40, 20, 60, 10, 30]
// Constraints:
// 1 <= Number of nodes <= 104
// 1 <= Data of a node <= 109

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) {
        // Your code here
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node *t = q.front();
            q.pop();
            if(!t){
                v.push_back(-1);
                continue;
            }
            v.push_back(t->data);
            q.push(t->left);
            q.push(t->right);
        }
        
        return v;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        // Your code here
        Node *root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        
        int i = 1, n = arr.size();
        
        while(i < n){
            Node *t = q.front();
            q.pop();
            if(arr[i] != -1){
                Node *lt = new Node(arr[i]);
                q.push(lt);
                t->left = lt;
            }
            
            i++;
            
            if(i < n && arr[i] != -1){
                Node *rt = new Node(arr[i]);
                q.push(rt);
                t->right = rt;
            }
            
            i++;
        }
        
        return root;
    }
};
