class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int numCols = matrix[0].size();
        int maxIdenticalRows = 0;
        
        for(auto& currentRow : matrix) {
            vector<int> flippedRow(numCols);
            int identicalRowCount = 0;
            
            for(int i = 0; i < numCols; ++i) {
                flippedRow[i] = 1 - currentRow[i];
            }
            
            for(auto& compareRow : matrix) {
                if(compareRow == currentRow || compareRow == flippedRow) {
                    identicalRowCount++;
                }
            }
            
            maxIdenticalRows = max(maxIdenticalRows, identicalRowCount);
        }
        
        return maxIdenticalRows;
    }
};