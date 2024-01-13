Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

Example 1:

Input:
N = 10
Linked List = 30->23->28->30->11->14->
              19->16->21->25 
Output : 11 14 16 19 21 23 25 28 30 30 
Explanation :
The resultant linked list is sorted.
Example 2:

Input : 
N = 7
Linked List=19->20->16->24->12->29->30 
Output : 12 16 19 20 24 29 30 
Explanation : 
The resultant linked list is sorted.
Your task:
You don't need to read input or print anything. Your task is to complete the function insertionSort() which takes the head of the linked list, sorts the list using insertion sort algorithm and returns the head of the sorted linked list.
 
Expected Time Complexity : O(n2)
Expected Auxiliary Space : O(1)
 
Constraints:
0 <= n <= 5*103

//Driver Code Starts

//Initial Template for C++



#include<bits/stdc++.h>

using namespace std;



/* Link list node */

struct Node {

	int data;

	struct Node *next;

	Node(int x) {

		data = x;

		next = NULL;

	}

};



/* Function to print linked list */

void printList(struct Node *head)

{

	struct Node *temp = head;

	while (temp != NULL)

	{

		printf("%d ", temp->data);

		temp = temp->next;

	}

}







//Driver Code Ends



//User function Template for C++



/*Link list node

struct Node {

	int data;

	struct Node *next;

	Node(int x) {

		data = x;

		next = NULL;

	}

};*/



class Solution

{

    public:

    Node* insertionSort(struct Node* head)

    {

        //code here

        Node *p=head;

        Node *q=p;

        while (q->next!=NULL){

            Node *ch=q;

            int val=q->data;

            p=q->next;

            while (p!=NULL){

                if(val>=p->data){

                    ch=p;

                    val=p->data;

                }

                p=p->next;

            }

            ch->data=q->data;

            q->data=val;

            q=q->next;

        }

        

        return head;

    }

    

};



//Driver Code Starts



int main()

{

	int T;

	cin >> T;



	while (T--)

	{

		int n;

		cin >> n;



		Node *head = NULL;

		Node *temp = head;



		for (int i = 0; i < n; i++) {

			int data;

			cin >> data;

			if (head == NULL)

				head = temp = new Node(data);

			else

			{

				temp->next = new Node(data);

				temp = temp->next;

			}

		}



        Solution ob;



		head = ob.insertionSort(head);

		printList(head);



		cout << "\n";







	}

	return 0;

}

//Driver Code Ends
