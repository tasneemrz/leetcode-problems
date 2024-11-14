class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = findMax(nums);
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(findSum(nums, mid) <= threshold) 
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return low;
    }

private:
    int findSum(vector<int>& nums, int divisor) {
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += ceil(double(nums[i]) / double(divisor));
        }
            
        return sum;
    }
    
    int findMax(vector<int>& nums) {
        int maxVal = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i]);
        }
        
        return maxVal;
    }
};