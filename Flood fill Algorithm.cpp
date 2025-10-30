class Solution {
    
    void bfs(vector<vector<int>>& answer, int n, int m, int sr, int sc, int newColor, int oldColor){
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
        
            answer[row][col] = newColor;
            
            int rval[4] = {-1, 0, 1, 0};
            int cval[4] = {0, -1, 0, 1};
            
            for(int i = 0; i < 4; i++){
                int r = row + rval[i];
                int c = col + cval[i];
                if(r >= 0 &&  r < n && c >= 0 && c < m && answer[r][c] == oldColor){
                    answer[r][c] = newColor;
                    q.push({r, c});
                }
            }
        }
    }    
    
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // code here
        
        
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>> answer = image;
        
        if(newColor == image[sr][sc])return image;
        
        bfs(answer, n, m, sr, sc, newColor, image[sr][sc]);
        
        return answer;
    }
};