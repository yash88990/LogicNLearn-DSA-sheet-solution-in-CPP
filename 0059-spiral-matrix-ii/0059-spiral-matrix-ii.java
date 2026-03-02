class Solution {
    public int[][] generateMatrix(int n) {

        int[][] ans = new int[n][n];

        int top = 0, left = 0;
        int right = n - 1, bottom = n - 1;

        int num = 1;

        while (num <= n * n) {

            // left → right
            for (int i = left; i <= right; i++) {
                ans[top][i] = num++;
            }
            top++;

            // top → bottom
            for (int i = top; i <= bottom; i++) {
                ans[i][right] = num++;
            }
            right--;

            // right → left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans[bottom][i] = num++;
                }
                bottom--;
            }

            // bottom → top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans[i][left] = num++;
                }
                left++;
            }
        }

        return ans;
    }
}