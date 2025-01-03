class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        long long prefixSum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            prefixSum += nums[i];
            if(prefixSum >= (sum-prefixSum)) {
                ans++;
            }
        }

        return ans;
    }
};