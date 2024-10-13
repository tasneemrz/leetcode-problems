class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> indices(k, 0);
        vector<int> range = {0, INT_MAX};

        while(1) {
            int curMin = INT_MAX;
            int curMax = INT_MIN;
            int minListIndex = 0;

            for(int i = 0; i < k; i++) {
                int curEle = nums[i][indices[i]];

                if(curEle < curMin) {
                    curMin = curEle;
                    minListIndex = i;
                }

                curMax = max(curMax, curEle);
            }

            if(curMax - curMin < range[1] - range[0]) {
                range[0] = curMin;
                range[1] = curMax;
            }

            if(++indices[minListIndex] == nums[minListIndex].size()) break;
        }

        return range;
    }
};