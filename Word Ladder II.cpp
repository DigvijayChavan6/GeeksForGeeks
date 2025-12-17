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