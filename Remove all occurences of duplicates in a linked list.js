// Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list. 

// Examples:

// Input: Linked List = 23->28->28->35->49->49->53->53
// Output: 23 35
// Explanation: The duplicate numbers are 28, 49 and 53 which are removed from the list.

// Input: Linked List = 11->11->11->11->75->75
// Output: Empty list
// Explanation: All the nodes in the linked list have duplicates. Hence the resultant list would be empty.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)
// Constraints:
// 1 ≤ size(list) ≤ 105

/*
class Node{
    constructor(data){
        this.data = data;
        this.next = null;
    }
}

let head;
This is method only submission.
You only need to complete the below method.
*/

class Solution {
    del(n){
        let v=n.data;
        while(n && v == n.data){
            n=n.next;
        }
        return n;
    }
    removeAllDuplicates(node) {
        // your code here
        let start=new Node(0);
        let prev=start;
        start.next=node;
        while(node && node.next){
            if(node.data == node.next.data){
                prev.next=this.del(node);
                node=prev.next;
            }else{
                prev=node;
                node=node.next;
            }
        }
        return start.next;
    }
}