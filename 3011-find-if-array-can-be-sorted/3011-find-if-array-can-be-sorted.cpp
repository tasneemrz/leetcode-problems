class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(nums[j+1] < nums[j] && __builtin_popcount(nums[j+1]) == __builtin_popcount(nums[j]))
                    swap(nums[j], nums[j+1]);
            }
        }

        for(int i = 0; i < n-1; i++) {
            if(nums[i] > nums[i+1]) 
                return false;
        }

        return true;
    }

private:
    int setBits(int num) {
        int countSetBits = 0;

        while(num) {
            if ((num & 1) != 0)
                countSetBits++;
            num >>= 1;
        }

        return countSetBits;
    }
};