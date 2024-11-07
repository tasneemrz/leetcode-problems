class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];
        int numSetBits = __builtin_popcount(nums[0]);
        int maxOfPrevSegment = INT_MIN;

        for(int i = 1; i < nums.size(); i++) {
            if(__builtin_popcount(nums[i]) == numSetBits) {
                maxOfSegment = max(maxOfSegment, nums[i]);
                minOfSegment = min(minOfSegment, nums[i]);
            } 
            else {
                if(minOfSegment < maxOfPrevSegment) return false;
                
                maxOfPrevSegment = maxOfSegment;
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numSetBits = __builtin_popcount(nums[i]);
            }      
        } 
        
        if(minOfSegment < maxOfPrevSegment) return false;

        return true;
    }
};