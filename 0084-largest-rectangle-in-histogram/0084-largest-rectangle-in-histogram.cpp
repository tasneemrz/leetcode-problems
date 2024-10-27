class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestArea = INT_MIN;
        int n = heights.size();
        stack<int> st;

        for(int i = 0; i <= n; i++) {
            // if stack !empty and the iteration reached i = n or,
            // if stack !empty and heights[st.top] has a histogram higher than the current heighst[i] histogram
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                // if histogram at the top of stack is >= current histogram
                // then the current heights[i] is the smallest histogram to the right of st.top()
                // so we find the area by taking the height of the stack top histogram as the height of rect
                int rect_h = heights[st.top()];
                st.pop();

                // after popping the stack, to find the width:
                // if stack empty; means no smaller histogram to the left; width taken from 0->i (where i is index of the smallest right histogram)
                // if stack not empty; means now the stack top element is the smallest histogram to the left; width will be right_smallest_index - left_smallest_index - 1
                int rect_w = (st.empty()) ? i : i - st.top() - 1;

                // update the largest area
                largestArea = max(largestArea, rect_h * rect_w);
            }

            st.push(i);
        }

        return largestArea;
    }
};