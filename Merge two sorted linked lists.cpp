// Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.

// Examples:

// Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
// Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
// Explanation:

// Input: head1 = 1 -> 1, head2 = 2 -> 4
// Output: 1 -> 1 -> 2 -> 4
// Explanation:

// Constraints:
// 1 <= no. of nodes<= 103
// // 0 <= node->data <= 105

/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node *beg = new Node(0);
        Node *trav = beg;
        
        while(head1 && head2){
            if(head1->data < head2->data){
                trav->next = head1;
                trav = head1;
                head1 = head1->next;
            }else{
                trav->next = head2;
                trav = head2;
                head2 = head2->next;
            }
        }
        
        while(head1){
            trav->next = head1;
            trav = head1;
            head1 = head1->next;
        }
        
        while(head2){
            trav->next = head2;
            trav = head2;
            head2 = head2->next;
        }
        
        return beg->next;
    }
};