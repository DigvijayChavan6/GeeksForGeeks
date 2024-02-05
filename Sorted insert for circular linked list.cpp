// Given a sorted circular linked list of length n, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

// Example 1:

// Input:
// n = 3
// LinkedList = 1->2->4
// (the first and last node is connected, i.e. 4 --> 1)
// data = 2
// Output: 
// 1 2 2 4
// Explanation:
// We can add 2 after the second node.
// Example 2:

// Input:
// n = 4
// LinkedList = 1->4->7->9
// (the first and last node is connected, i.e. 9 --> 1)
// data = 5
// Output: 
// 1 4 5 7 9
// Explanation:
// We can add 5 after the second node.
// Your Task:
// The task is to complete the function sortedInsert() which should insert the new node into the given circular linked list and return the head of the linked list.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 0 <= n <= 105

class Solution{
    public:
    Node *sortedInsert(Node* head, int data){
        Node *nd=new Node(data);
        nd->next=nd;
        Node *pre=head,*p=head;
        if(p==NULL)return nd;
        if(p->next == p){
            p->next=nd;
            nd->next=p;
            if(data<p->data)return nd;
            return p;
        }
        do{ pre=pre->next; }while(pre->next !=head);
        if(data <= p->data){
            pre->next=nd;
            nd->next=p;
            return nd;
        }
        else{
            int flag=0;
            do{
                pre=p;
                p=p->next;
                if(data <= p->data){
                    pre->next=nd;
                    nd->next=p;
                    flag=1;
                    break;
                }
            }while(p != head);
            if(flag==0){
                pre->next=nd;
                nd->next=head;
            }
        }
        return head;
    }
};