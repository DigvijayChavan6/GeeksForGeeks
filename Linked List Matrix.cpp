// Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

// Input: mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
// Output: 

// Input: mat = [[23, 28], [23, 28]]
// Output:

// Expected Time Complexity: O(n2)
// Expected Space Complexity: O(n2)

// Constraints:
// 1 <= mat.size() <=15
// 1 <= mat[i][j] <=104

/*structure of the node of the linked list is as
struct Node{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // code Here
        
        int row = mat.size(), col = mat[0].size();
        vector<vector<Node*>> nodes(row, vector<Node*>(col, NULL));
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                nodes[i][j] = new Node(mat[i][j]);
                if(i+1<row){
                    nodes[i][j]->right = nodes[i+1][j];
                }
                if(j+1<col){
                    nodes[i][j]->down = nodes[i][j+1];
                }
            }
        }
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(i+1<row){
                    nodes[i][j]->down = nodes[i+1][j];
                }
                if(j+1<col){
                    nodes[i][j]->right = nodes[i][j+1];
                }
            }
        }
        return nodes[0][0];
    }
};