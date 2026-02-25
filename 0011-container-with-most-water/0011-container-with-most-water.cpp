class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0  , right = height.size() - 1, maxarea = INT_MIN;
        while(left < right){
            int hei = min(height[left] , height[right]);
            int wid = right - left;
            int area = hei * wid;
            maxarea = max(area , maxarea);
            if(height[left] < height[right])left++;
            else right--;
        }
        return maxarea;
    }
};