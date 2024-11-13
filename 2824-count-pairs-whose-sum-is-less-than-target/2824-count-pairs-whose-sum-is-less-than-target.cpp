class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            int bound = target-nums[i];
            
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] >= bound) 
                    break;
                ans++;
            }
        }
        
        return ans;
    }
};