class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxBitwiseOR = 0;
        int n = nums.size();

        for(int num : nums) {
            maxBitwiseOR |= num;
        }

        int subsets = 1 << n;
        int ans = 0;

        for(int mask = 0; mask < subsets; mask++) {
            int bitwiseOR = 0;

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    bitwiseOR |= nums[i];
                }
            }

            if(bitwiseOR == maxBitwiseOR) {
                ans++;
            }
        } 

        return ans;
    }
};