class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        for (int rotationOffset = 0; rotationOffset < size; ++rotationOffset) {
            bool isMatch = true;
            for (int index = 0; index < size; ++index) {
                if (nums[(rotationOffset + index) % size] !=
                    sortedNums[index]) {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch) {
                return true;
            }
        }

        return false;
    }
};