// Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
// If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
// If the input linked list has 1 node, then it should return NULL

// Example 1:

// Input:
// LinkedList: 1->2->3->4->5
// Output: 1 2 4 5
// Example 2:

// Input:
// LinkedList: 2->4->6->7->5->1
// Output: 2 4 6 5 1
// Your Task:
// The task is to complete the function deleteMid() which should delete the middle element from the linked list and return the head of the modified linked list. If the linked list is empty then it should return NULL.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= n <= 105
// 1 <= value <= 109

/*
struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

// Deletes middle of linked list and returns head of the modified list

class Solution{
    public:
    Node* deleteMid(Node* head){
        Node *mid=head,*go=head,*prev=head;
        while(go != NULL && go->next != NULL){
            prev=mid;
            mid=mid->next;
            go=go->next->next;
        }
        prev->next=mid->next;
        free(mid);
        return head;
    }
};