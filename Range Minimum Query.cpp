// Given an array A[ ] and its size N your task is to complete two functions  a constructST  function which builds the segment tree  and a function RMQ which finds range minimum query in a range [a,b] of the given array.

// Input:
// The task is to complete two functions constructST and RMQ.
// The constructST function builds the segment tree and takes two arguments the array A[ ] and the size of the array N.
// It returns a pointer to the first element of the segment tree array.
// The RMQ function takes 4 arguments the first being the segment tree st constructed, second being the size N and then third and forth arguments are the range of query a and b. The function RMQ returns the min of the elements in the array from index range a and b. There are multiple test cases. For each test case, this method will be called individually.

// Output:
// The function RMQ should return the min element in the array from range a to b.

// Example:

// Input (To be used only for expected output) 
// 1
// 4
// 1 2 3 4
// 2
// 0 2 2 3
// Output
// 1 3
// Explanation
// 1. For query 1 ie 0 2 the element in this range are 1 2 3 
//    and the min element is 1. 
// 2. For query 2 ie 2 3 the element in this range are 3 4 
//    and the min element is 3.
// Constraints:
// 1<=T<=100
// 1<=N<=10^3+1

// 1<=A[i]<=10^9
// 1<=Q(no of queries)<=10000
// 0<=a<=b

/* The functions which 
builds the segment tree */

int *seg;

void build(int seg[], int p, int arr[], int l, int r){
    if(l == r){
        seg[p] = arr[l];
        return;
    }
    int mid = l+(r-l)/2;
    build(seg, 2*p+1, arr, l, mid);
    build(seg, 2*p+2, arr, mid+1, r);
    seg[p]=min(seg[2*p+1], seg[2*p+2]);
}

int *constructST(int arr[],int n){
  //Your code here
    seg = new int[4*n];
    build(seg, 0, arr, 0, n);
    return seg;
}
/* The functions returns the
 min element in the range
 from a and b */

int getMin(int p, int l, int r, int a, int b){
    if(l > b || r < a){
        return INT_MAX;
    }
    if(l >= a && r <= b){
        return seg[p];
    }
    int mid = l+(r-l)/2;
    int lt = getMin(2*p+1, l, mid, a, b);
    int rt = getMin(2*p+2, mid+1, r, a, b);
    return min(lt, rt);
}



int RMQ(int st[] , int n, int a, int b){
//Your code here
    return getMin(0, 0, n, a, b);
}
