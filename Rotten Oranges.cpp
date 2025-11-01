class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        
        int n = mat.size();
        int m = mat[0].size();
        
        int time = 0;
        
        vector<vector<int>> peti = mat;
        
        queue<vector<pair<int, int>>> q;
        
        vector<pair<int, int>> temp;
        
        for(int i = 0; i < n; i++){
            for(int  j = 0; j < m; j++){
                if(peti[i][j] == 2){
                    temp.push_back({i, j});
                }
            }
        }
        
        q.push(temp);
        temp.clear();
        
        while(!q.empty()){
            vector<pair<int, int>> level = q.front();
            q.pop();
            
            int r[] = {0, -1, 0, 1};
            int c[] = {1, 0, -1, 0};
            
            for(auto p : level){
                
                for(int i = 0; i < 4; i++){
                    int row = p.first + r[i];
                    int col = p.second + c[i];
                    
                    if(row >= 0 && row < n && col >= 0 && col < m){
                        if(peti[row][col] == 1){
                            peti[row][col] = 2;
                            temp.push_back({row, col});
                        }
                    }
                }
                
            }
            
            if(!temp.empty()){
                q.push(temp);
                temp.clear();
            }
            
            time++;
        }
        
        for(int i = 0; i < n; i++){
            for(int  j = 0; j < m; j++){
                if(peti[i][j] == 1){
                    return -1;
                }
            }
        }
        
        
        return time-1;
    }
};