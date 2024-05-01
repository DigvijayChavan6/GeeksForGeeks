// Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival. 

// Example 1:

// Input:
// n = 9
// linked list: a -> b -> c -> d -> e -> f -> g -> h -> i 
// Output: 
// a -> e -> i -> b -> c -> d -> f -> g -> h
// Explanation: 
// After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.

// Example 2:

// Input:
// n = 8
// linked list: a -> b -> a -> b -> d -> e -> e -> d 
// Output: 
// a -> a -> e -> e -> b -> b -> d -> d
// Explanation: 
// After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.

// Your Task:
// Your task is to complete the function arrangeCV(), which takes head of linked list and arranges the list in such a way that all the vowels come before the consonants while maintaining the order of their arrival and returns the head of the updated linked list.

// Expected Time Complexity :  O(n)
// Expected Auxiliary Space :  O(1)

// Constraints:
// 1 <= n <= 104
// 'a' <= elements of linked list <= 'z'

/*
Structure of the node of the linked list is as
struct Node{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    Node* arrangeCV(Node* head) {
        // Code here
        Node *cur=head;
        string conso="", vow="", all="";
        char c;
        while(cur){
            c=cur->data;
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')vow+=c;
            else conso+=c;
            cur=cur->next;
        }
        all=vow+conso;
        cur=head;
        for(char c : all){
            cur->data=c;
            cur=cur->next;
        }
        return head;
    }
};