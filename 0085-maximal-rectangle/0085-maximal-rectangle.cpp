class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        int maxArea = 0;
        int i = 0;
        
        while (i < n) {
            if (stk.empty() || heights[i] >= heights[stk.top()]) {
                stk.push(i++);
            } else {
                int tp = stk.top();
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, heights[tp] * width);
            }
        }
        
        while (!stk.empty()) {
            int tp = stk.top();
            stk.pop();
            int width = stk.empty() ? i : i - stk.top() - 1;
            maxArea = max(maxArea, heights[tp] * width);
        }
        
        return maxArea;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        for (int i = 0; i < rows; ++i) {
            // Update heights based on current row
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            // Calculate the maximum area for the current row
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;

    }
};