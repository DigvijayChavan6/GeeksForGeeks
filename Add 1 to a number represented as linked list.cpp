// A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

// Example 1:

// Input:
// LinkedList: 4->5->6
// Output: 457
// Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
// Example 2:

// Input:
// LinkedList: 1->2->3
// Output: 124 
// Your Task:
// Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
// Note: The head represents the left-most digit of the number.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 1021

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution{
    public:
    Node* rev(Node *p){
        Node *q=NULL,*r=NULL;
        while(p != NULL){
            q=p->next;
            p->next=r;
            r=p;
            p=q;
        }
        return r;
    }
    void add(Node* p){
        int carry=1;
        Node* prev=p;
        while(p != NULL){
            prev=p;
            int val=carry + p->data;
            p->data=val%10;
            if(val>=10)carry=1;
            else carry=0;
            p=p->next;
        }
        if(carry == 1){
            prev->next=new Node(1);
        }
    }
    Node* addOne(Node *head) {
        head=rev(head);
        add(head);
        return rev(head);
    }
};