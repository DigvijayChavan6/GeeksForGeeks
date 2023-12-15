// Given a sorted doubly linked list and an element X, your need to insert the element X into correct position in the sorted DLL.

// Example:

// Input:
// LinkedList:

// X = 9
// Output:

// Your Task:
// You only need to complete the function sortedInsert() that takes head reference and x as arguments and returns the head of the modified list. The printing and checking tasks are done by the driver code.

// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= Number of nodes <= 103


/*structure of the node of the DLL is as
struct Node {
	int data;
	struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
//Return the head after insertion
Node* sortedInsert(Node * head, int x){
	Node *p=head,*reserve;
	Node *node=(Node*)malloc(sizeof(Node));
	node->data=x;
	if(p->next==NULL || p->data>x){
	    if(p->data<=x){
	        p->next=node;
	        node->next=NULL;
	        node->prev=p;
	        return p;
	    }
	    node->prev=NULL;
	    node->next=p;
	    p->prev=node;
	    return node;
	}
	
	do{
	    if(p->data>=x){
	        Node *t=p->prev;
	        node->prev=t;
	        node->next=p;
	        p->prev=node;
	        t->next=node;
	        break;
	    }
	    reserve=p;
	    p=p->next;
	}while(p!=NULL);
	if(p==NULL){
	    reserve->next=node;
	    node->prev=reserve;
	    node->next=NULL;
	}
	return head;
};