class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n - k + 1);
        
        for(int i = 0; i < n-k+1; i++) {
            bool isConsecutiveAndSorted = true;

            for(int j = i; j < i + k - 1; j++) {
                if(nums[j+1] - nums[j] != 1) {
                    isConsecutiveAndSorted = false;
                    break;
                }
            }

            if(isConsecutiveAndSorted) {
                result[i] = nums[i+k-1];
            } else {
                result[i] = -1;
            }
        }
        
        return result;
    }
};