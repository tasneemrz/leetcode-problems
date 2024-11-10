class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int shortestLength = INT_MAX;
        int left = 0;
        int right = 0;
        vector<int> bitCounts(32, 0);
        
        while(right < nums.size()) {
            updateBitCounts(bitCounts, nums[right], 1);
            
            while(left <= right && convertBitCountsToNumber(bitCounts) >= k) {
                shortestLength = min(shortestLength, right - left + 1);
                
                updateBitCounts(bitCounts, nums[left], -1);
                left++;
            }
            
            right++;
        }
        
        return shortestLength == INT_MAX ? -1 : shortestLength;
    }
    
    void updateBitCounts(vector<int>& bitCounts, int number, int delta) {
        for(int bitPos = 0; bitPos < 32; bitPos++) {
            if((number >> bitPos) & 1) {
                bitCounts[bitPos] += delta;
            }
        }
    }
    
    int convertBitCountsToNumber(const vector<int>& bitCounts) {
        int result = 0;
        
        for(int bitPos = 0; bitPos < 32; bitPos++) {
            if(bitCounts[bitPos] != 0) {
                result |= (1 << bitPos);
            }
        }
        
        return result;
    }
};