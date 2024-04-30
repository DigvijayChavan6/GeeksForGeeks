// Given two numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

// For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

// Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

// Example 1:

// Input:
// n = 2
// num1 = 45 (4->5->null)
// m = 3
// num2 = 345 (3->4->5->null)
// Output: 
// 3->9->0->null  
// Explanation: 
// For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).

// Example 2:

// Input:
// n = 4
// num1 = 0063 (0->0->6->3->null)
// m = 2
// num2 = 07 (0->7->null)
// Output: 
// 7->0->null
// Explanation: 
// For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).

// Your Task:
// The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

// Expected Time Complexity: O(n+m)
// Expected Auxiliary Space: O(max(n,m)) for the resultant list.

// Constraints:
// 1 <= n, m <= 104

class Solution{
    public:
    struct Node* reduce(struct Node *n){
        while(n->data==0 && n->next){
            struct Node *t=n;
            n=n->next;
            delete(t);
        }
        return n;
    }
    struct Node* rev(struct Node* n){
        struct Node *t1=n, *t2=NULL, *t3=NULL;
        while(t1){
            t2=t1->next;
            t1->next=t3;
            t3=t1;
            t1=t2;
        }
        return t3;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* a, struct Node* b){
        a=reduce(a);
        b=reduce(b);
        a=rev(a);
        b=rev(b);
        int carry=0;
        struct Node *my=new Node(0);
        struct Node *p=my;
        while(a || b){
            int x=0, y=0;
            if(a)x=a->data;
            if(b)y=b->data;
            p->next=new Node((x+y+carry)%10);
            if(x+y+carry >= 10)carry=1;
            else carry=0;
            p=p->next;
            if(a)a=a->next;
            if(b)b=b->next;
        }
        if(carry)p->next=new Node(1);
        if(!my->next)return my;
        return rev(my->next);
    }
};