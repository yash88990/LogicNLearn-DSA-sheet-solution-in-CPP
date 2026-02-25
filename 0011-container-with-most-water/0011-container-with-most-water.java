class Solution {
    public int maxArea(int[] height) {
        int left = 0  , right = height.length - 1, maxarea = Integer.MIN_VALUE;
        while(left < right){
            int hei = Math.min(height[left] , height[right]);
            int wid = right - left;
            int area = hei * wid;
            maxarea = Math.max(area , maxarea);
            if(height[left] < height[right])left++;
            else right--;
        }
        return maxarea;
    }
}