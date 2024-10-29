class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size(); 

        vector<vector<int>> mem(m, vector<int>(n, 0));

        for (int j = n - 1; j >= 0; j--) {
            for (int i = m - 1; i >= 0; i--) {
                int curValue = grid[i][j];

                int diagUpMem = ((j != n - 1 && i != 0) && (grid[i - 1][j + 1] > curValue))
                    ? 1 + mem[i - 1][j + 1] // if we can move to this cell
                    : 0; // if we cannot move to this cell

                int rightMem = ((j != n - 1) && (grid[i][j + 1] > curValue))
                    ? 1 + mem[i][j + 1]
                    : 0;

                int diagDownMem = ((i != m - 1 && j != n - 1) && (grid[i + 1][j + 1] > curValue))
                    ? 1 + mem[i + 1][j + 1]
                    : 0;

                mem[i][j] = max({diagUpMem, rightMem, diagDownMem});
            }
        }

        int ans = -1;
        for (int i = 0; i < m; i++) {
            ans = max(ans, mem[i][0]);
        }

        return ans;
    }
};