// Given a list of N words. Count the number of words that appear exactly twice in the list.

// Example 1:

// Input:
// N = 3
// list = {Geeks, For, Geeks}
// Output: 1
// Explanation: 'Geeks' is the only word that 
// appears twice. 
// Example 2:

// Input:
// N = 8
// list = {Tom, Jerry, Thomas, Tom, Jerry, 
// Courage, Tom, Courage}
// Output: 2
// Explanation: 'Jerry' and 'Courage' are the 
// only words that appears twice. 

// Your Task:  
// You dont need to read input or print anything. Complete the function countWords() which takes integer N and list of strings as input parameters and returns the number of words that appear twice in the list.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)  


// Constraints:
// 1<= N <= 104

class Solution{
    public:
        int countWords(string list[], int n){
            map<string,int> mp;
            for(int i=0;i<n;i++){
                mp[list[i]]++;
            }
            int cnt=0;
            for(auto p : mp){
                if(p.second == 2)cnt++;
            }
            return cnt;
        }
};