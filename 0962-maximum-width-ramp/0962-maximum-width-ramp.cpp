class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int maxWidthRamp = 0;
        int n = nums.size();
        stack<int> st;

        for(int i = 0; i < n; i++) {
            if(st.empty() || nums[i] < nums[st.top()])
                st.push(i);
        }

        for(int j = n - 1; j >= 0; j--) {
            while(!st.empty() && nums[j] >= nums[st.top()]) {
                maxWidthRamp = max(maxWidthRamp, j - st.top());
                st.pop();
            }
        }

        return maxWidthRamp;
    }
};