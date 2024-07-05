// Given a Binary Tree. You need to find and return the vertical width of the tree.

// Examples :

// Input:
//          1
//        /    \
//       2      3
//      / \    /  \
//     4   5  6   7
//             \   \
//              8   9
// Output: 6
// Explanation: The width of a binary tree is
// the number of vertical paths in that tree.



// The above tree contains 6 vertical lines.
// Input:
//      1
//     /  \
//    2    3
// Output: 3
// Explanation: The above tree has 3 vertical lines, hence the answer is 3.
// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(height of the tree).

// Constraints:
// 0 <= number of nodes <= 104


class Solution {
    void getWidth(Node* root, int &small, int &big, int l){
        if(!root)return;
        small=min(small, l);
        big=max(big, l);
        getWidth(root->left, small, big, l-1);
        getWidth(root->right, small, big, l+1);
    }
    public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        // code here
        int small=INT_MAX;
        int big=INT_MIN;
        getWidth(root, small, big, 0);
        return abs(small)+abs(big)+1;
    }
};
