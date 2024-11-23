class Solution {
public:
    const char STONE = '#';
    const char OBSTACLE = '*';
    const char EMPTY = '.';
    
    void applyGravity(vector<vector<char>>& rotatedBox, int i, int j) {
        int nextRowWithStone = -1;
        
        for(int k = i - 1; k >= 0; k--) {
            if (rotatedBox[k][j] == OBSTACLE)
                break;
            if(rotatedBox[k][j] == STONE) {
                nextRowWithStone = k;
                break;
            }
        }
        
        if (nextRowWithStone != -1) {
            rotatedBox[nextRowWithStone][j] = EMPTY;
            rotatedBox[i][j] = STONE;
        }
    }
    
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
            for (int i = n - 1; i >= 0; i--) {
                if (rotatedBox[i][j] == EMPTY) 
                    applyGravity(rotatedBox, i, j);
            }
        }
        
        return rotatedBox;
    }
};