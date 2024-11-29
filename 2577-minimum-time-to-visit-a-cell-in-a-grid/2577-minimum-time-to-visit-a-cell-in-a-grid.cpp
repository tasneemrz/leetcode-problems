class Solution {
public:
    #define pip pair<int, pair<int, int>>
    
    int minimumTime(vector<vector<int>>& grid) {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[0][1] > 1 + grid[0][0] && grid[1][0] > 1+grid[0][0])
            return -1;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pip, vector<pip>, greater<pip>> minHeap;
        minHeap.push({0,{0,0}});
        visited[0][0] = true;
        
        while(!minHeap.empty()) {
            pip curr = minHeap.top();
            minHeap.pop();
            
            int time = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;
            
            if(x == m-1 && y == n-1)
                return time;
            
            for(int i = 0; i < 4; i++) {
                int newX = x + dir[i];
                int newY = y + dir[i+1];
                
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    int newTime = time+1;
                    if(grid[newX][newY] > newTime) {
                        newTime = (grid[newX][newY]-time) & 1 ? grid[newX][newY] : grid[newX][newY]+1;
                    }
                    minHeap.push({newTime, {newX, newY}});
                }
            }
        }
        
        return -1;
    }
};