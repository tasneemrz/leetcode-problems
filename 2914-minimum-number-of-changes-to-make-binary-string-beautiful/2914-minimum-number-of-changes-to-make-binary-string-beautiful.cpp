class Solution {
public:
    int minChanges(string s) {
        char currChar = s[0];
        int consecutiveCount = 0;
        int minChangesReq = 0;
        
        for(char c : s) {
            if(c == currChar) {
                consecutiveCount++;
                continue;
            } 
            
            if(consecutiveCount % 2 == 0) {
                consecutiveCount = 1;
            }
            else {
                consecutiveCount = 0;
                minChangesReq++;
            }
            
            currChar = c;
        }
        
        return minChangesReq;
    }
};