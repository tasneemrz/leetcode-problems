class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> bannedSet;
        
        for(int num : banned) {
            bannedSet.insert(num);
        }
        
        int sum = 0;
        int count = 0;
        int maxLength = INT_MIN;
        
        for(int i = 1; i <= n; i++) {
            if(bannedSet.find(i) != bannedSet.end()) {
                continue;
            }
            
            if(sum + i <= maxSum) {
                sum += i;
                count++;
                maxLength = max(maxLength, count);
            } else {
                break;
            }
        }
        
        return (maxLength == INT_MIN) ? 0 : maxLength;
    }
};