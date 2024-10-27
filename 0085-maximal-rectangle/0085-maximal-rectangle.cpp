class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = INT_MIN;
        int n = heights.size();
        stack<int> st;

        for(int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int rect_h = heights[st.top()];
                st.pop();

                int rect_w = (st.empty()) ? i : i - st.top() - 1;

                largestArea = max(largestArea, rect_h * rect_w);
            }

            st.push(i);
        }

        return largestArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            int area = largestRectangleArea(heights);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};