// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string startWord, string targetWord,
                                         vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> answer;
        vector<string> used;
        queue<vector<string>> q;
        
        q.push({startWord});
        used.push_back(startWord);
        st.erase(startWord);
        
        int level = 0;
        
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();

            if(vec.size() > level){
                level++;
                for(string str : used){
                    st.erase(str);
                }
                used.clear();
            }
            
            string word = vec[vec.size()-1];
            
            if(word == targetWord){
                if(answer.size() == 0){
                    answer.push_back(vec);
                }else if(answer[0].size() == vec.size()){
                    answer.push_back(vec);
                }
            }
            
            for(int i = 0; i < word.size(); i++){
                char ori = word[i];
                for(char  j = 'a'; j <= 'z'; j++){
                    word[i] = j;
                    if(st.find(word) != st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();
                        used.push_back(word);
                    }
                }
                word[i] = ori;
            }
        }
        
        return answer;
    }
};



class Solution {
    int size;
    vector<vector<string>> answer;
    unordered_set<string> st;
    unordered_map<string, int> mp;
    unordered_map<string, vector<string>> parent;

    void dfs(string &start, string &word, vector<string> &temp){
        if(word == start){
            vector<string> r = temp;
            reverse(r.begin(), r.end());
            answer.push_back(r);
            return;
        }

        for(string &p : parent[word]){
            temp.push_back(p);
            dfs(start, p, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<string>> findSequences(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {
        size = beginWord.size();
        st.insert(wordList.begin(), wordList.end());

        if(!st.count(endWord)) return answer;

        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 0;

        bool found = false;

        // -------- BFS (fixed) --------
        while(!q.empty() && !found){
            int qsz = q.size();
            unordered_set<string> usedThisLevel;

            while(qsz--){
                string curr = q.front();
                q.pop();
                int lev = mp[curr];

                for(int i = 0; i < size; i++){
                    string next = curr;
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == curr[i]) continue;
                        next[i] = c;

                        if(!st.count(next)) continue;

                        if(!mp.count(next)){
                            mp[next] = lev + 1;
                            q.push(next);
                            parent[next].push_back(curr);
                            usedThisLevel.insert(next);
                        }
                        else if(mp[next] == lev + 1){
                            parent[next].push_back(curr);
                        }

                        if(next == endWord) found = true;
                    }
                }
            }

            for(auto &w : usedThisLevel) st.erase(w);
        }

        // -------- DFS --------
        vector<string> temp;
        temp.push_back(endWord);
        dfs(beginWord, endWord, temp);

        return answer;
    }
};
