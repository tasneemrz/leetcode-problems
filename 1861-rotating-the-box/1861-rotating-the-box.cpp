class Solution {
public:
    const char STONE = '#';
    const char OBSTACLE = '*';
    const char EMPTY = '.';
    
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++) 
                rotatedBox[i][j] = box[j][i];
        
        for (int i = 0; i < n; i++) {
            reverse(rotatedBox[i].begin(), rotatedBox[i].end());
        }
        
        for (int j = 0; j < m; j++) {
            int lowestRowWithEmptyCell = n - 1;
            
            for (int i = n - 1; i >= 0; i--) {
                if (rotatedBox[i][j] == STONE) {
                    rotatedBox[i][j] = EMPTY;
                    rotatedBox[lowestRowWithEmptyCell][j] = STONE;
                    lowestRowWithEmptyCell--;
                } 
                
                if(rotatedBox[i][j] == OBSTACLE) {
                    lowestRowWithEmptyCell = i - 1;
                }
            }
        }
        
        return rotatedBox;
    }
};