class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;

        sort(nums.begin(), nums.end());

        while(i < j) {
            if(nums[i] < -nums[j]) i++;
            else if(-nums[i] < nums[j]) j--;
            else if(-nums[i] == nums[j]) return nums[j];
        }

        return -1;
    }
};