class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> cache(rows, vector<int>(cols, 0));

        int sqCount = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) { 
                if(matrix[i][j] == 1) {
                    if(i == 0 || j == 0) cache[i][j] = 1;
                    else
                        cache[i][j] = min({cache[i-1][j], cache[i-1][j-1], cache[i][j-1]}) + 1;
                }
                    
                sqCount += cache[i][j];
            }
        }

        return sqCount;
    }
};