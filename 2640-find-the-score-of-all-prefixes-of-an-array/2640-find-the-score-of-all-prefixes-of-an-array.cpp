class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        int prefixMax = nums[0];
            
        for(int i = 0; i < n; i++) {
            // update the max value till this iteration
            prefixMax = max(prefixMax, nums[i]);
            
            // find the conversion value for the currrent iteration
            long long conver_i = nums[i] + prefixMax;
            
            // update the new value of nums by adding the conversion value to the previous array elements value
            if(i == 0) 
                ans[i] = conver_i;
            else
                ans[i] = conver_i + ans[i-1];
        }
        
        return ans;
    }
};