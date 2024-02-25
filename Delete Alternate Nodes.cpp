// Given a Singly Linked List of size n, delete all alternate nodes of the list.

//  Example 1:

// Input:
// LinkedList: 1->2->3->4->5->6
// Output: 1->3->5
// Explanation: Deleting alternate nodes results in the linked list with elements 1->3->5.
// Example 2:

// Input:
// LinkedList: 99->59->42->20
// Output: 99->42
// Your Task:
// Your task is to complete the function deleteAlt() which takes the head of the linked list in the input parameter and modifies the given linked list accordingly.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <=n<= 105
// 1 <= node.data <= 106

/*
Structure of the node of the binary tree
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    int data = x;
	    next = NULL;
	}
};
*/
// Complete this function
class Solution{
    public:
    void deleteAlt(struct Node *head){
        struct Node *p=head, *t=NULL;
        while(p != NULL && p->next != NULL){
            t = p->next;
            p->next = t->next;
            free(t);
            p=p->next;
        }
    }
};
