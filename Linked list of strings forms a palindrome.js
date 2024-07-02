// Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.

// Example:

// Input:

// Output : true
// Explanation: As string "abcddcba" is palindrome the function should return true.

// Input:

// Output : false
// Explanation: As string "abcdba" is not palindrome the function should return false.

// Expected Time Complexity:  O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 <= Node.data.length<= 103
// 1<=list.length<=103

// User function Template for javascript

/*LINKED LIST NODE
class Node {
  constructor(x){
    this.data = x;
    this.next = null;
  }
}
*/

/**
 * @param {Node} head
 * @return {boolean}
 */

class Solution {
    compute(head) {
        // code here
        let str="";
        while(head){
            str+=head.data;
            head=head.next;
        }
        let size=str.length;
        for(let i=0;i<=size/2;i++){
            if(str[i] != str[size-i-1]){
                return false;
            }
        }
        return true;
    }
}