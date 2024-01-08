// Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

// Example 1:

// Input:
// N = 2, M = 2
// list1 = 1->3
// list2 = 2->4
// Output:
// 4->3->2->1
// Explanation:
// After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.
// Example 2:

// Input:
// N = 4, M = 3
// list1 = 5->10->15->40 
// list2 = 2->3->20
// Output:
// 40->20->15->10->5->3->2
// Explanation:
// After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
// Your Task:
// The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

// Expected Time Complexity : O(N+M)
// Expected Auxiliary Space : O(1)

// Constraints:
// 0 <= N, M <= 104

/*
The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution{
    public:
    Node* doSome(Node *a){
        Node *prev=NULL,*cur=a,*next;
        while(cur!=NULL){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    struct Node * mergeResult(Node *a,Node *b){
        // your code goes here
        a=doSome(a);
        b=doSome(b);
        Node *head,*p;
        if(a==NULL)return b;
        if(b==NULL)return a;
        
        if(a!=NULL && b!=NULL){
            if(a->data>b->data){
                head=a;
                p=a;
                a=a->next;
            }
            else{
                head=b;
                p=b;
                b=b->next;
            }
        }
        while(a!=NULL && b!=NULL){
            if(a->data>b->data){
                p->next=a;
                p=a;
                a=a->next;
            }
            else{
                p->next=b;
                p=b;
                b=b->next;
            }
        }
        if(a!=NULL)p->next=a;
        if(b!=NULL)p->next=b;
        return head;
    }  
};