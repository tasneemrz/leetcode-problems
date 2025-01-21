class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        if(n < 2) 
            return 0;

        long long topSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long bottomSum = 0;
        long long minSum = LONG_MAX;

        for(int pp = 0; pp < n; ++pp) {
            topSum -= grid[0][pp];
            minSum = min(minSum, max(topSum, bottomSum));
            bottomSum += grid[1][pp];
        }

        return minSum;
    }
};