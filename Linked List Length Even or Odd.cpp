// Given a linked list of size n, your task is to complete the function isLengthEvenOrOdd() which contains the head of the linked list and check whether the length of the linked list is even or odd.

// Example1:

// Input:
// 3
// 9 4 3
// Output:
// Odd
// Explanation:
// The length of linked list is 3 which is odd.
// Example2:

// Input:
// 6
// 12 52 10 47 95 0
// Output:
// Even
// Explanation:
// The length of linked list is 6 which is even.
// User Task:

// Since this is a functional problem you don't have to worry about input, you just have to complete the function isLengthEvenOrOdd() 
// which takes the head of the linked list as the input parameter and returns 0 if the length of the linked list is even
// otherwise returns 1.

// Expected Time Complexity: O(log(n))
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= n <= 104
// 1 <= elements of the linked list <= 103

/*structure of a node of the linked list is as
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
// Function should return 0 is length is even else return 1

int isLengthEvenOrOdd(struct Node* head){
    long long int cnt=0;
    while(head){
        cnt++;
        head=head->next;
    }
    return cnt%2==1;
}
