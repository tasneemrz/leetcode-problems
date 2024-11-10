class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int shortestLength = n + 1;
        
        for(int i = 0; i < n; i++) {
            int OR = 0;
            
            for(int j = i; j < n; j++) {
                OR |= nums[j];
                
                if(OR >= k) {
                    shortestLength = min(shortestLength, j-i+1);
                }
            }
        }
        
        if(shortestLength > n) return -1;
        return shortestLength;
    }
};