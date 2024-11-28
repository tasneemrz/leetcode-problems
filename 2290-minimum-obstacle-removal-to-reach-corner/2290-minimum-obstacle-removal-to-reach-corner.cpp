class Solution {
    #define pip pair<int, pair<int, int>>
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        priority_queue<pip, vector<pip>, greater<pip>> minHeap;
        minHeap.push({0,{0,0}});
        visited[0][0] = true;
        
        while(!minHeap.empty()) {
            pip curr = minHeap.top();
            minHeap.pop();
            
            int x = curr.second.first;
            int y = curr.second.second;
            int cost = curr.first;
            
            if(x == m-1 && y == n-1) 
                return cost;
            
            for(int i = 0; i < 4; i++) {
                int newX = x + dir[i];
                int newY = y + dir[i+1];
                
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    if (grid[newX][newY] == 1) 
                        minHeap.push({cost+1,{newX, newY}});
                    else 
                        minHeap.push({cost, {newX, newY}});
                }
            }
        }
        
        return 0;
    }
};