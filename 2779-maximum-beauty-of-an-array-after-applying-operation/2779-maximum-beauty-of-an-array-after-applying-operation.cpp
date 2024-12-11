class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int maxCount = 0;
        int winCount = 0;
        int left = 0, right = 0;
        int n = nums.size();
        
        while(right < n) {
            while(right < n && (nums[right] - nums[left]) <= 2*k) {
                winCount++;
                right++;
            } 
            
            maxCount = max(maxCount, winCount);
            if(right == n) 
                break;
            
            while(left <= right && (nums[right]-nums[left]) > 2*k) {
                winCount--;
                left++;
            }
        }
        
        return maxCount;
    }
};