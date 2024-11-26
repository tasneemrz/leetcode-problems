class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        for(auto& edge : edges) {
            inDegree[edge[1]]++;
        }
        
        int champion = -1;
        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                if(champion == -1) {
                    champion = i;
                }
                else {
                    return -1;
                }
            }
        }
        
        return champion;
    }
};