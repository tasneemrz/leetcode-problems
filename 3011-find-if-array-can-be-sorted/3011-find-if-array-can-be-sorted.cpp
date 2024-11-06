class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(nums[j+1] >= nums[j]) 
                    continue;
                else {
                    if(__builtin_popcount(nums[j+1]) == __builtin_popcount(nums[j]))
                        swap(nums[j], nums[j+1]);
                    else
                        return false;
                }
            }
        }

        return true;
    }
};