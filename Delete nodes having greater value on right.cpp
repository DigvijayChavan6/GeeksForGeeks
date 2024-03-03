// Given a singly linked list, remove all the nodes in the list which have any node on their right whose value is greater. (Not just immediate Right , but entire List on the Right)

// Example 1:

// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15 11 6 3
// Explanation: Since, 12, 10, 5 and 2 are
// the elements which have greater elements
// on the following nodes. So, after deleting
// them, the linked list would like be 15,
// 11, 6, 3.
// Example 2:

// Input:
// LinkedList = 10->20->30->40->50->60
// Output: 60
// Explanation: All the nodes except the last
// node has a greater value node on its right,
// so all the nodes except the last node must
// be removed.
// Your Task:
// The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. 
// The printing is done by the driver code,

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ size of linked list ≤ 105
// 1 ≤ element of linked list ≤ 105

// Note: Try to solve the problem without using any extra space.

/*
The structure of linked list is the following

struct Node{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
    public:
    Node* rev(Node *p){
        Node *a=NULL, *b=NULL;
        while(p != NULL){
            a=p->next;
            p->next=b;
            b=p;
            p=a;
        }
        return b;
    }
    Node *compute(Node *head){
        Node *p=rev(head);
        Node *f=p, *back=p;
        p=p->next;
        while(p!=NULL){
            if(back->data <= p->data){
                back->next=p;
                back=p;
            }
            p=p->next;
        }
        back->next=NULL;
        return rev(f);
    }
    
};