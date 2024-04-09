// Given a single linked list of size N, calculate the sum of the last M nodes.

// Example 1:

// Input:
// N = 6, M = 3
// 5 9 6 3 4 10
// Output:
// 17
// Explanation:
// Sum of last three nodes in the linked list is 3 + 4 + 10 = 17.

// Example 2:

// Input:
// N = 2,  M = 2
// 1 2
// Output:
// 3
// Explanation:
// Sum of last two nodes in the linked list is 2 + 1 = 3.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function sumOfLastN_Nodes(), which takes two arguments as input, the reference pointer to the head of the linked list and the integer N. Return an Integer which is the sum of last M nodes.

// Constraints:
// 1<=T<=100
// 1<=N<=M<=1000

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
* /
    // your task is to complete this function
    // function should return sum of last n nodes
    void getSum(struct Node *p, int &n, int &sum)
{
    if (p == NULL || n == 0)
        return;
    getSum(p->next, n, sum);
    if (n > 0)
        sum += p->data;
    n--;
}
int sumOfLastN_Nodes(struct Node *head, int n)
{
    int sum = 0;
    getSum(head, n, sum);
    return sum;
}