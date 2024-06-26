// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

// Example 1:

// Input : 
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output : 
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

 
// Example 2:

// Input : 
// N = 8
// A[] = {12, -1, -7, 8, -15, 30, 16, 28}
// K = 3
// Output :
// -1 -1 -7 -15 -15 0 

 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function printFirstNegativeInteger() which takes the array A[], its size N and an integer K as inputs and returns the first negative number in every window of size K starting from the first till the end. If a window does not contain a negative integer , then return 0 for that window.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(K)

// Constraints:
// 1 <= N <= 105
// -105 <= A[i] <= 105
// 1 <= K <= N

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    vector<long long> vec;
    queue<pair<long long, long long>> q;
    long long i=0;
    bool t=true;
    for(i=0;i<K;i++){
        q.push({i, A[i]});
        if(t && A[i]<0){
            t=false;
            vec.push_back(A[i]);
        }
    }
    if(t)vec.push_back(0);
    for(i=K;i<N;i++){
        q.push({i, A[i]});
        while(!q.empty() && (q.front().second > 0 || q.front().first <= i-K)){
            q.pop();
        }
        if(q.empty())vec.push_back(0);
        else vec.push_back(q.front().second);
    }
    return vec;                                             
}