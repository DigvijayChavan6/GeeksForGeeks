// Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

// Examples:

// Input: LinkedList = 1 <--> 3 <--> 4, x = 3
// Output: 1 3  
// Explanation: 
// After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 

// Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
// Output: 5 2 9
// Explanation:

// Expected Time Complexity: O(n)
// Expected Auxilliary Space: O(1)

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

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // Your code here
        Node *start=head, *temp=head;
        if(x == 1){
            temp=head->next;
            delete(head);
            if(temp){
                temp->prev=NULL;
            }
            return temp;
        }
        while(x){
            temp=head;
            head=head->next;
            x--;
        }
        if(head){
            temp->prev->next=head;
            head->prev=temp->prev;
        }else{
            temp->prev->next=NULL;
        }
        delete(temp);
        return start;
    }
};