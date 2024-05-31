// Given a struct array of type Height, having two elements feet and inches. Find the maximum height among n heights, where height is calculated sum of feet and inches after converting feet into inches.

// Example 1:

// Input:
// n = 2
// h1 -> 1 2
// h2 -> 2 1
// Output: 
// 25
// Explanation:
// (1, 2) and (2, 1) are respective given heights.
// After converting both heigths in to inches,
// we get 14 and 25 as respective heights.
// So, 25 is the maximum height.

// Input:
// n = 3
// h1 -> 3 2
// h2 -> 2 3
// h3 -> 1 2
// Output: 
// 38
// Explanation:
// (3, 2), (2,3) and (1, 2) are respective given heights.
// After converting both heigths in to inches,
// we get 38,25 and 14 as respective heights.
// So, 38 is the maximum height.

// Your Task: Your task is to only complete the function of find maximum height from given array.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 1 <= n <= 105

int findMax(struct Height arr[], int n) {
    // Code here
    int answer=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=arr[i].feet*12+arr[i].inches;
        answer=max(answer, sum);
    }
    return answer;
}