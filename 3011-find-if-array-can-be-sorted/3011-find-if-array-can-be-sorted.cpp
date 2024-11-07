class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        // left to right pass
        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) {
                if(__builtin_popcount(nums[i]) == __builtin_popcount(nums[i+1])) {
                    swap(nums[i], nums[i+1]);
                } 
                else return false;
            }     
        } 
        
        // right to left pass
        for(int i = n-1; i > 0; i--) {
            if(nums[i] < nums[i-1]) {
                if(__builtin_popcount(nums[i]) == __builtin_popcount(nums[i-1])) {
                    swap(nums[i], nums[i-1]);
                } 
                else return false;
            }     
        } 

        return true;
    }
};