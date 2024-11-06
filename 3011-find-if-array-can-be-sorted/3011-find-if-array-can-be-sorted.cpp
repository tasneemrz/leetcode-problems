class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n-i-1; j++) {
                if(nums[j+1] < nums[j] && setBits(nums[j+1]) == setBits(nums[j]))
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

        for(int mask = 1; mask <= 256; mask<<=1) {
            if ((mask & num) != 0)
                countSetBits++;
        }

        return countSetBits;
    }
};