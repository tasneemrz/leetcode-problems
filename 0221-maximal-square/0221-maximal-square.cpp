class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // cache to store the max length square that can be formed for each cell
        // each cell will be taken as the bottom right corner of the square
        vector<vector<int>> cache(rows, vector<int>(cols, 0));

        // iterate over all the other cells in matrix from top to bottom
        int maxLength = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) { 
                if(matrix[i][j] == '1') {
                    // all cells in first row and column can only make a square of size 1
                    if(i == 0 || j == 0) cache[i][j] = 1;
                    else
                        cache[i][j] = min({cache[i-1][j], cache[i-1][j-1], cache[i][j-1]}) + 1;
                }
                    
                maxLength = max(maxLength, cache[i][j]);
            }
        }

        return maxLength * maxLength;
    }
};
