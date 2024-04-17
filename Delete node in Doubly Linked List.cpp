// Given a doubly linked list and a position. The task is to delete a node from given position (position starts from 1) in a doubly linked list.

// Example 1:

// Input:
// LinkedList = 1 <--> 3 <--> 4 
// x = 3
// Output: 1 3  
// Explanation: After deleting the node at
// position 3 (position starts from 1),
// the linked list will be now as 1->3.

// Example 2:

// Input:
// LinkedList = 1 <--> 5 <--> 2 <--> 9  
// x = 1
// Output: 5 2 9

// Your Task:
// The task is to complete the function deleteNode() which should delete the node at given position and return the head of the linkedlist.

// Expected Time Complexity : O(n)
// Expected Auxilliary Space : O(1)

// Constraints:
// 2 <= size of the linked list(n) <= 105
// 1 <= x <= n
// 1 <= node.data <= 109

 
/* Structure of Node
struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
*/

class Solution{
    public:
    Node* deleteNode(Node *head, int x){
        //Your code here
        Node *p=head, *t=p, *d=NULL;
        if(x == 1){
            head->next->prev=NULL;
            d=head;
            delete(d);
            return head->next;
        }
        while(true){
            t=p;
            p=p->next;
            x--;
            if(x == 1){
                d=p;
                p=p->next;
                t->next=p;
                if(p){
                    p->prev=t;
                }
                delete(d);
                break;
            }
        }
        return head;
    }
};
