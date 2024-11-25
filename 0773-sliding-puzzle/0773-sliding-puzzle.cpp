class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // convert the 2d matrix to a string because it is easier to compare
        string start = "";
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 3; j++) {
                start += to_string(board[i][j]);
            }
        }
        
        string target = "123450";
        
        // initialize queue for the bfs traversal
        queue<string> q;
        q.push(start);
        
        // initialize a map to keep track of what index we should swap 0 with in the string
        unordered_map<int, vector<int>> swapingIndexes;
        swapingIndexes[0] = {1, 3};
        swapingIndexes[1] = {0, 2, 4};
        swapingIndexes[2] = {1, 5};
        swapingIndexes[3] = {0, 4};
        swapingIndexes[4] = {1, 3, 5};
        swapingIndexes[5] = {4, 2};
        
        // initialize a map to keep track of visited states and insert start to it
        unordered_set<string> visited;
        visited.insert(start);
        
        // apply bfs
        int level = 0;
        while(!q.empty()) {
            int levelSize = q.size();
            
            while(levelSize--) {
                string currState = q.front();
                q.pop();
                
                if(currState == target) {
                    return level;
                }
                
                int indexOfZero = currState.find('0');
                for(int swapIdx : swapingIndexes[indexOfZero]) {
                    string newState = currState;
                    swap(newState[indexOfZero], newState[swapIdx]);
                    
                    if(visited.find(newState) == visited.end()) {
                        q.push(newState);
                        visited.insert(newState);
                    }
                }
            }
            
            level++;
        }
        
        return -1;
    }
};

/*
    time complexity:
        positions are 6
        total possible states are 6!;
        in worst case we may visit all possible states = O(6!)
        
    space complexity:
        queue can take up the max size of O(6!)
*/

