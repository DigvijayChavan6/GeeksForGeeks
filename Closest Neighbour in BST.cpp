// Given the root of a binary search tree and a number n, find the greatest number in the binary search tree that is less than or equal to n. 

// Example 1 :

// Input : 

// n = 24
// Output : 
// 21
// Explanation : The greatest element in the tree which 
//               is less than or equal to 24, is 21. 
//               (Searching will be like 5->12->21)

// Example 2 :

// Input : 

// n = 4
// Output : 
// 3
// Explanation : The greatest element in the tree which 
//               is less than or equal to 4, is 3. 
//               (Searching will be like 5->2->3)

// Your task :
// You don't need to read input or print anything. Your task is to complete the function findMaxForN() which takes the root of the BST, and the integer n as input parameters and returns the greatest element less than or equal to n in the given BST, Return -1 if no such element exists.

// Expected Time Complexity: O(Height of the BST)
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 <= n <= 103
// 1 <= elements of the BST <= 103
// All nodes are unique in the BST

/*
//Structure of the Node of the BST is as
struct Node {
    int key;
    Node* left, *right;
};


   'N' is the element
   'size' is the total element in BST
  */

class Solution
{
public:
    void getAnswer(Node *p, int &answer, int n, bool back)
    {
        if (back || !p)
            return;
        getAnswer(p->left, answer, n, back);
        if (p->key <= n)
        {
            answer = p->key;
        }
        else
            back = true;
        getAnswer(p->right, answer, n, back);
    }
    int findMaxForN(Node *root, int n)
    {
        int answer = -1;
        getAnswer(root, answer, n, false);
        return answer;
    }
};
