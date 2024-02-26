// Given two linked list head1 and head2 with distinct elements, your task is to complete the function countPairs(), which returns the count of all distinct pairs from both lists whose sum is equal to the given value x.

// Note: The  two numbers of a pair should be parts of different lists, and pair(x,y) and pair(y,x) are considered to be same.

// Example 1:

// Input:
// head1 = 1->2->3->4->5->6
// head2 = 11->12->13
// x = 15
// Output: 3
// Explanation: There are total 3 pairs whose sum is 15 : (4,11) , (3,12) and (2,13)
// Example 2:

// Input:
// head1 = 7->5->1->3
// head2 = 3->5->2->8
// x = 10
// Output: 2
// Explanation: There are total 2 pairs whose sum is 10 : (7,3) and (5,5)
// Your Task:
// You only need to implement the given function countPairs() that take two linked list head1 and head2 and return the count of distinct pairs whose sum is equal to x.

// Expected Time Complexity: O(length(head1)+lenght(head2)).
// Expected Auxiliary Space: O(length(head1)) or O(length(head2)).

// Constraints:
// 1<=length(head1), lenght(head2)<=105
// 1 <= node.data <= 109
// 1<= x <= 109
// Note : All elements in each linked list are unique.

/*
Structure of the node of the linked list is as
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
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_map<int,bool> mp;
        while(head1 != NULL){
            mp[head1->data]=true;
            head1=head1->next;
        }
        int cnt=0;
        while(head2 != NULL){
            if(mp[x-head2->data]){
                cnt++; 
            }
            head2=head2->next;
        }
        return cnt;
    }
};