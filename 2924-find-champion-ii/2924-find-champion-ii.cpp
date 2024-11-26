class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        for(auto& edge : edges) {
            inDegree[edge[1]]++;
        }
        
        int startPoints = 0;
        int champion;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                startPoints++;
                champion = i;
            }
        }
        
        return (startPoints > 1) ? -1 : champion;
    }
};