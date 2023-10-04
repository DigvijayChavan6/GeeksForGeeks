// Given a singly linked list and an integer x.Delete xth node from the singly linked list.

// Example 1:

// Input: 1 -> 3 -> 4 
//        x = 3
// Output: 1 -> 3
// Explanation:
// After deleting the node at 3rd
// position (1-base indexing), the
// linked list is as 1 -> 3. 
// Example 2:

// Input: 1 -> 5 -> 2 -> 9 
// x = 2
// Output: 1 -> 2 -> 9
// Explanation: 
// After deleting the node at 2nd
// position (1-based indexing), the
// linked list is as 1 -> 2 -> 9.
// Your task: Your task is to complete the method deleteNode() which takes two arguments: the address of the head of the linked list and an integer x. The function returns the head of the modified linked list.

// Constraints:
// 2 <= N <= 105
// 1 <= x <= N


/* Link list Node 
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

/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    //Your code here
    Node *t,*p=head;
    if(x==1)return p->next;
    while(x!=1){
        t=p;
        p=p->next;
        x--;
    }
    t->next=p->next;
    delete(p);
    return head;
}