class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis_left_of_i(n, 1);
        vector<int> lds_right_of_i(n, 1);

        // Compute LIS for each index from the left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    lis_left_of_i[i] = max(lis_left_of_i[i], lis_left_of_i[j] + 1);
                }
            }
        }

        // Compute LDS for each index from the right
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    lds_right_of_i[i] = max(lds_right_of_i[i], lds_right_of_i[j] + 1);
                }
            }
        }

        int maxMountainSeq = 0;
        
        // Find the maximum mountain sequence by combining LIS and LDS for each peak
        for (int i = 1; i < n - 1; i++) {
            if (lis_left_of_i[i] > 1 && lds_right_of_i[i] > 1) {
                int mountainSeq = lis_left_of_i[i] + lds_right_of_i[i] - 1;
                maxMountainSeq = max(maxMountainSeq, mountainSeq);
            }
        }

        return n - maxMountainSeq;
    }
};