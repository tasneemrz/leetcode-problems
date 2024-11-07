class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxElements = 0;
        int n = candidates.size();
        
        for(int bit = 0; bit < 24; bit++) {
            int elements = 0;
            
            for(int num : candidates) 
                if(num & (1 << bit)) 
                    elements++;
                
            maxElements = max(maxElements, elements);
        }
        
        return maxElements;
    }
};