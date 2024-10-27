class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // cache to store the max length square that can be formed starting from each cell
        // each cell will be taken as the top left corner of the square
        vector<vector<int>> cache(m, vector<int>(n, -1));

        // base case for all the columns of each row
        for(int row = 0; row < m; row++) {
            if(matrix[row][n-1] == '1')
                cache[row][n-1] = 1;
            else
                cache[row][n-1] = 0;
        }

        // base case for all the last rows of each column
        for(int col = 0; col < n; col++) {
            if(matrix[m-1][col] == '1')
                cache[m-1][col] = 1;
            else
                cache[m-1][col] = 0;
        }

        // iterate over all the other cells in matrix from bottom right
        for(int i = m-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                if(matrix[i][j] == '1') {
                    cache[i][j] = min(cache[i+1][j], min(cache[i][j+1], cache[i+1][j+1])) + 1;
                }
                else {
                    cache[i][j] = 0;
                }
            }
        }

        // iterate over cache to find the square max side length 
        int maxLength = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                maxLength = max(maxLength, cache[i][j]);
            }
        }

        return maxLength * maxLength;
    }
};