class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3,0);

        for(int num : nums) {
            if(num == 0) colors[0]++;
            if(num == 1) colors[1]++;
            if(num == 2) colors[2]++;
        }

        int j = 0;
        for(int i = 0; i < 3; i++) {
            while(colors[i] > 0) {
                nums[j] = i;
                colors[i]--;
                j++;
            }
        }
    }
};