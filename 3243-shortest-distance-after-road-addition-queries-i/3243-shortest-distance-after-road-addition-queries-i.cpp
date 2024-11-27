class Solution {
public:
    int shortestPath(vector<vector<int>>& adj, int n) {
        queue<int> q;
        q.push(0);
        
        vector<bool> visited(n, false);
        visited[0] = true;
        int distance = 0;
        
        while(!q.empty()) {
            int levelSize = q.size();
            
            while(levelSize--) {
                int currCity = q.front();
                q.pop();
                
                // reached destination
                if(currCity == n-1) {
                    return distance;
                }
                
                // iterate through the adjacency list of the current city
                for(int adjCity : adj[currCity]) {
                    if(!visited[adjCity]) {
                        visited[adjCity] = true;
                        q.push(adjCity);
                    }
                }
            }
            // after completing each level distance incremented
            distance++;
        }
        
        return distance;
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // adjacency list
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            adj[i].push_back(i+1);
        }
        
        vector<int> res;
        // iterate through each query
        for(auto& query : queries) {
            // add the new path connection to the adjacency list
            adj[query[0]].push_back(query[1]);
            // find the shortest path after adding the new path using BFS
            res.push_back(shortestPath(adj, n));
        }
        
        return res;
    }
};