class Solution {
    int minValueIndex(vector<int>& nums) {
        int minIndex = 0;
        int minValue = nums[0];
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < minValue) {
                minValue = nums[i];
                minIndex = i;
            }
        }
        
        return minIndex;
    }
    
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--) {
            int minIndex = minValueIndex(nums);
            nums[minIndex] *= multiplier; 
        }
        
        return nums;
    }
};