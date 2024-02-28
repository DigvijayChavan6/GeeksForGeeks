// Given a singly linked list and a key, count the number of occurrences of the given key in the linked list.

// Example 1:

// Input:
// n = 7
// Link List = 1->2->1->2->1->3->1
// key = 1
// Output: 4
// Explanation: 1 appears 4 times. 
// Example 2:

// Input:
// n = 5
// Link List = 1->2->1->2->1
// key = 3
// Output: 0
// Explanation: 3 appears 0 times.
// Your Task:
// You dont need to read input or print anything. Complete the function count() which takes the head of the link list and search_for i.e- the key as input parameters and returns the count of occurrences of the given key.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 0 ≤ n ≤ 105

/*
  Node is defined as 
struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}*head;
*/
class Solution{
    public:
    int count(struct node* head, int search_for){
        int cnt = 0;
        while(head != NULL){
            if(head->data == search_for){
                cnt ++;
            }
            head = head->next;
        }
        return cnt;
    }
};