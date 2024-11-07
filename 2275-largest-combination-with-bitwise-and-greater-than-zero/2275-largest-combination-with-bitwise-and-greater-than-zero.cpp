class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxElements = 0;
        int n = candidates.size();
        
        for(int mask = 1; mask <= (1 << 24); mask <<= 1) {
            int elements = 0;
            
            for(int i = 0; i < n; i++) 
                if((mask & candidates[i]) != 0) 
                    elements++;
                
            maxElements = max(maxElements, elements);
        }
        
        return maxElements;
    }
};