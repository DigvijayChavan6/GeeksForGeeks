// Given a linked list of size N and a key. The task is to insert the key in the middle of the linked list.

// Example 1:

// Input:
// LinkedList = 1->2->4
// key = 3
// Output: 1 2 3 4
// Explanation: The new element is inserted
// after the current middle element in the
// linked list.

// Example 2:

// Input:
// LinkedList = 10->20->40->50
// key = 30
// Output: 10 20 30 40 50
// Explanation: The new element is inserted
// after the current middle element in the
// linked list and Hence, the output is
// 10 20 30 40 50.

 

// Your Task:
// The task is to complete the function insertInMiddle() which takes head reference and element to be inserted as the arguments. The printing is done automatically by the driver code.

// Expected Time Complexity : O(N)
// Expected Auxilliary Space : O(1)

// Constraints:
// 1 <= N <= 104

 

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to insert a node in the middle of the linked list.
Node* insertInMiddle(Node* head, int x)
{
	// Code here
	Node *f=head,*l=head,*tp;
	struct Node *vl=(struct Node*)malloc(sizeof(head));
	vl->data=x;
	while(l!=NULL && l->next!=NULL && f!=NULL){
	    tp=f;
	    f=f->next;
	    l=l->next->next;
	}
	if(l==NULL){
	    vl->next=tp->next;
	    tp->next=vl;
	}
	else {
	    vl->next=f->next;
	    f->next=vl;
	}
	return head;
}