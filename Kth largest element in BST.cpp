// Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

// Example 1:

// Input:
//       4
//     /   \
//    2     9
// k = 2 
// Output: 4
// Example 2:

// Input:
//        9
//         \ 
//           10
// K = 1
// Output: 10
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(H) where H is max recursion stack of height H at a given time.

// Constraints:
// 1 <= N <= 105
// 1 <= K <= N

class Solution{
    public:
    int lar,cnt,n;
    void getLar(Node *p,int K){
        if(p!=NULL){
            getLar(p->left,K);
            if(K==cnt)return;
            lar=p->data;
            cnt++;
            getLar(p->right,K);
        }
    }
    void get(Node *p){
        if(p!=NULL){
            get(p->right);
            n++;
            get(p->left);
        }
    }
    int kthLargest(Node *root, int K){
        //Your code here
        lar=0;
        cnt=0;
        n=0;
        get(root);
        getLar(root,n-K+1);
        return lar;
    }
};