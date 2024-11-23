class Solution {
public:
    const char STONE = '#';
    const char OBSTACLE = '*';
    const char EMPTY = '.';
    
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        
        vector<vector<char>> rotatedBox(n, vector<char>(m, '.'));
        
        for (int i = 0; i < m; i++) {
            int lowestRowWithEmptyCell = n - 1;
            
            for (int j = n - 1; j >= 0; j--) {
                if (box[i][j] == STONE) {
                    rotatedBox[lowestRowWithEmptyCell][m - i - 1] = STONE;
                    lowestRowWithEmptyCell--;
                } 
                
                if(box[i][j] == OBSTACLE) {
                    rotatedBox[j][m - i - 1] = OBSTACLE;
                    lowestRowWithEmptyCell = j - 1;
                }
            }
        }
        
        return rotatedBox;
    }
};