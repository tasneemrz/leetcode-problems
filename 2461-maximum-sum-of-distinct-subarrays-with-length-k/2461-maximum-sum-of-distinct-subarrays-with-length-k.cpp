class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, j = 0;
        long long maxSum = 0, sum = 0;
        unordered_map<int, int> hash;

        while (i <= j && j < nums.size()) {
            if (j-i+1 <= k) {
                sum += nums[j];
                hash[nums[j]]++;
                j++;
            }
            else {
                if (hash.size() == k) 
                    maxSum = max(maxSum, sum);
                
                hash[nums[i]]--;
                if(hash[nums[i]] == 0) hash.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
        }

        if(hash.size() == k) {
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};