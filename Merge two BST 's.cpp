// Given two BSTs, return elements of merged BSTs in sorted form.

// Examples :

// Input:
// BST1:
//        5
//      /   \
//     3     6
//    / \
//   2   4  
// BST2:
//         2
//       /   \
//      1     3
//             \
//              7
//             /
//            6
// Output: 1 2 2 3 3 4 5 6 6 7
// Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
// Input:
// BST1:
//        12
//      /   
//     9
//    / \    
//   6   11
// BST2:
//       8
//     /  \
//    5    10
//   /
//  2
// Output: 2 5 6 8 9 10 11 12
// Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
// Expected Time Complexity: O(m+n)
// Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

// Constraints:
// 1 ≤ Number of Nodes ≤ 105

/*
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
class Solution {
    void getData(Node *a, vector<int> &data){
        if(!a)return ;
        getData(a->left, data);
        data.push_back(a->data);
        getData(a->right, data);
    }
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> a_data, b_data, answer;
        getData(root1, a_data);
        getData(root2, b_data);
        int a=a_data.size(), b=b_data.size();
        int i=0, j=0;
        while(i<a && j<b){
            if(a_data[i] <= b_data[j])answer.push_back(a_data[i++]);
            else answer.push_back(b_data[j++]);
        }
        while(i<a)answer.push_back(a_data[i++]);
        while(j<b)answer.push_back(b_data[j++]);
        return answer;
    }
};