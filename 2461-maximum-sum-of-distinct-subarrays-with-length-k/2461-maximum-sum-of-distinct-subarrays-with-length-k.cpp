class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        long long maxSum = 0, sum = 0;
        unordered_map<int, int> hashNumCount;

        while (i <= j && j < nums.size()) {
            if (j-i+1 <= k) {
                sum += nums[j];
                hashNumCount[nums[j]]++;
                j++;
            }
            else {
                if (hashNumCount.size() == k) 
                    maxSum = max(maxSum, sum);
                
                hashNumCount[nums[i]]--;
                if(hashNumCount[nums[i]] == 0) hashNumCount.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
        }

        if(hashNumCount.size() == k) {
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};