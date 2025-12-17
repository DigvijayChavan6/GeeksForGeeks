class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        
        unordered_set<string> st;
        
        for(string str : wordList){
            st.insert(str);
        }
        
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        st.erase(startWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int lev = q.front().second;
            
            q.pop();
            
            if(word == targetWord)return lev;
            
            for(int i = 0; i < word.size(); i++){
                char ori = word[i];
                for(char  j = 'a'; j <= 'z'; j++){
                    word[i] = j;
                    if(st.find(word) != st.end()){
                        q.push({word, lev + 1});
                        st.erase(word);
                    }
                }
                word[i] = ori;
            }
        }
        
        return 0;
    }
};