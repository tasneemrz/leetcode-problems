class Solution {
    bool isPossible(int maxBalls, vector<int>& nums, int maxOperations) {
        int totalOperations = 0;

        for (int num : nums) {
            int operations = ceil(num / (double)maxBalls) - 1;
            totalOperations += operations;

            if (totalOperations > maxOperations) 
                return false;
        }

        return true;
    }
    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = 0;
        
        for(int num : nums) 
            high = max(high, num);
        
        while(low <= high) {
            int mid = (low + high) / 2;
            
            if(isPossible(mid, nums, maxOperations)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};