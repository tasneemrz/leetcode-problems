class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(subarrayWithTargetSum(target, nums, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            } 
        }
        
        if(low > nums.size()) 
            return 0;
        return low;
    }

private:
    bool subarrayWithTargetSum(int target, vector<int>& nums, int maxLength) {
        int sum = 0;
        int i = 0;
        int j = 0;
        
        while (i <= j && j < nums.size()) {
            sum += nums[j];
            
            if(j - i + 1 > maxLength) {
                sum -= nums[i];
                i++;
            }
            
            if (j - i + 1 == maxLength && sum >= target) {
                return true;
            }
        
            j++;
        }
        
        return false;
    }
};