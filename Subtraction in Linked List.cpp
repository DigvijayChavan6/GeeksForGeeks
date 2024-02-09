// You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

// Example 1:

// Input:
// L1 = 1->0->0
// L2 = 1->2
// Output: 88
// Explanation:  
// First linked list represents 100 and the
// second one represents 12. 12 subtracted from 100
// gives us 88 as the result. It is represented
// as 8->8 in the linked list.
// Example 2:

// Input:
// L1 = 0->0->6->3
// L2 = 7->1->0
// Output: 647
// Explanation: 
// First linked list represents 0063 => 63 and 
// the second one represents 710. 63 subtracted 
// from 710 gives us 647 as the result. It is
// represented as 6->4->7 in the linked list.
// Your Task:
// You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of two linked lists as input parameters and which should subtract the smaller number from the larger one represented by the given linked lists and return the head of the linked list representing the result.

// n and m are the length of the two linked lists respectively.
// Expected Time Complexity:  O(n+m)
// Expected Auxiliary Space: O(n+m)

// Constraints:
// 1 <= n <= 10000
// 0 <= values represented by the linked lists < 10n
// 0 <= values represented by the linked lists < 10m

class Solution{
public:
    string getStr(Node *h){
        string a="";
        while(h){
            char c=h->data + '0';
            a+=c;
            h=h->next;
        }
        return a;
    }
    string reduce(string a){
        string ans="0";
        int a_size=a.size();
        for(int i=0;i<a_size;i++){
            if(a[i] != '0'){
                ans=a.substr(i,a_size-i+1);
                break;
            }
        }
        return ans;
    }
    string getAns(string &a, string &b){
        a=reduce(a);
        b=reduce(b);
        int i=a.size()-1;
        int j=b.size()-1;
        if(i == j){
            int k=0;
            while(a[k] == b[k] && k<=i)k++; 
            if(!(k-1 == i) && k<=i && a[k]<b[k]){
                swap(i,j);
                swap(a,b);
            }
        }
        else if(i < j){
            swap(i,j);
            swap(a,b);
        }
        int carry=0;
        string ans="";
        while(j>=0 && i>=0){
            int a_a=a[i] - 48;
            int b_b=b[j] - 48 + carry;
            if(a_a < b_b){
                a_a += 10;
                carry = 1;
            }
            else carry = 0;
            char c=a_a - b_b;
            c+=48;
            ans=c + ans;
            i--;
            j--;
        }
        while(i>=0){
            int a_a=a[i] - 48;
            int b_b=carry;
            if(a_a < b_b){
                a_a += 10;
                carry = 1;
            }
            else carry = 0;
            char c=a_a - b_b;
            c+=48;
            ans=c + ans;
            i--;
        }
        return ans;
    }
    Node* getNode(string &s){
        s=reduce(s);
        int s_size=s.size();
        Node *h=new Node(s[0]-48);
        Node *p=h;
        for(int i=1;i<s_size;i++){
            p->next=new Node(s[i]-48);
            p=p->next;
        }
        return h;
    }
    Node* subLinkedList(Node* h_one, Node* h_two) {
        string a=getStr(h_one);
        string b=getStr(h_two);
        string s=getAns(a,b);
        return getNode(s);
    }
};
