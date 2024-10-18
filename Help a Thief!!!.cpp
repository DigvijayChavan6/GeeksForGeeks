// You have to help a thief to steal as many as GoldCoins as possible from a GoldMine. There he saw N Gold Boxes an each Gold Boxes consists of Ai Plates each plates consists of Bi Gold Coins. Your task is to print the maximum gold coins theif can steal if he can take a maximum of T plates.

 

// Example 1:

// Input:
// T = 3, N = 3 
// A[] = {1, 2, 3}
// B[] = {3, 2, 1}
// Output:
// 7
// Explanation:
// The thief will take 1 plate of coins
// from the first box and 2 plate of coins
// from the second plate. 3 + 2*2 = 7.
// Example 2:

// Input:
// T = 0, N = 3 
// A[] = {1, 3, 2}
// B[] = {2, 3, 1}
// Output:
// 0
// Explanation:
// The thief can't take any plates.
// So he can't steal any coins.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes 2 Integers T, and N and two arrays A and B of size N as input and returns the maximum number of gold coins the thief can steal if he can take a maximum of T plates.

 

// Expected Time Complexity: O(N*logN)
// Expected Auxiliary Space: O(N)

 

// Constraints:
// 0 <= T,N <= 104
// 1 <= A[i] <= 104
// 1 <= B[i] <= 104

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<N; ++i){
            pq.push({B[i], A[i]});
        }
        int answer = 0;
        for(int i=0; i<N; ++i){
            int b=pq.top().first;
            int a=pq.top().second;
            if(T > 0){
                if(T >= a){
                    T -= a;
                    answer += b*a;
                }else{
                    answer += b*T;
                    T=0;
                }
            }
            if(T == 0)break;
            pq.pop();
        }
        return answer;
    }
};