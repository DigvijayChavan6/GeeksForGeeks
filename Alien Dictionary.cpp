// A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

// Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

// However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

// A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

// Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

// Examples:

// Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
// Output: true
// Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
// The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
// The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
// The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
// The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
// So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
// Input: words[] = ["caa", "aaa", "aab"]
// Output: true
// Explanation: A possible corrct order of letters in the alien dictionary is "cab".
// The pair "caa" and "aaa" suggests 'c' appears before 'a'.
// The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
// So, 'c' → 'a' → 'b' is a valid ordering.
// Input: words[] = ["ab", "cd", "ef", "ad"]
// Output: ""
// Explanation: No valid ordering of letters is possible.
// The pair "ab" and "ef" suggests "a" appears before "e".
// The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
// Constraints:
// 1 ≤ words.length ≤ 500
// 1 ≤ words[i].length ≤ 100
// words[i] consists only of lowercase English letters.




class Solution {
    bool getEdge(string a, string b, vector<vector<int>> &graph, 
            int indegree[]){
        int len = min(a.size(), b.size());
        for(int i = 0; i < len; i++){
            if(a[i] != b[i]){
                graph[a[i]-'a'].push_back(b[i]-'a');
                indegree[b[i]-'a']++;
                return true;
            }
        }
        
        if(a.size() > b.size()){
            return false;
        }
        
        return true;
    }
  public:
    string findOrder(vector<string> &words) {
        // code here
        int chars[26] = {0};
        int len = 0;
        int V = 26;
        for(string w : words){
            for(char ch : w){
                if(!chars[ch-'a']){
                    chars[ch-'a'] = 1;
                    len++;
                }
            }
        }
        vector<vector<int>> graph(V);
        int indegree[V] = {0};
        queue<int> q;
        
        
        for(int i = 1; i < words.size(); i++){
            bool re = getEdge(words[i-1], words[i], graph, indegree);
            if(!re)return "";
        }
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0 && chars[i]){
                q.push(i);
            }
        }
        string ans = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += (node+'a');
            
            for(int next : graph[node]){
                indegree[next]--;
                if(indegree[next] == 0 && chars[next]){
                    q.push(next);
                }
            }
        }
        
        if(ans.size() == len)return ans;
        
        return "";
    }
};













