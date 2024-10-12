class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // iterate through each prime number in the nums array 
        for(int i = 0; i < nums.size(); i++) {
            bool found = false;
            
            // check if the condition applies to any number less than nums[i]
            for(int j = 0; j < nums[i]; j++) {
                // if condition applies then update ans[i] and break
                if((j | (j+1)) == nums[i]) {
                    ans[i] = j;
                    found = true;
                    break;
                } 
            }

            if(!found) {
                ans[i] = -1;
            }
        }

        return ans;
    }
};