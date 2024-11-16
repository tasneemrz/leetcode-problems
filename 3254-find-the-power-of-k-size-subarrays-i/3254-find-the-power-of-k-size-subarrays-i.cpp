class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k == 1) return nums;
        
        size_t n = nums.size();
        vector<int> result(n - k + 1, -1);
        int consecutiveCount = 1;
        
        for(size_t i = 0; i < n - 1; i++) {
            if(nums[i+1] - nums[i] == 1) {
                consecutiveCount++;
            } else {
                consecutiveCount = 1;
            }
            
            if(consecutiveCount >= k) {
                result[i - k + 2] = nums[i + 1];
            }
        }
        
        return result;
    }
};