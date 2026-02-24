import java.util.*;

class Solution {

    public void solve(int[] nums, List<List<Integer>> ans, int index) {

        // base case
        if (index >= nums.length) {
            List<Integer> temp = new ArrayList<>();
            for (int num : nums) {
                temp.add(num);
            }
            ans.add(temp);
            return;
        }

        for (int i = index; i < nums.length; i++) {

            // swap
            swap(nums, index, i);

            // recursive call
            solve(nums, ans, index + 1);

            // backtrack (swap back)
            swap(nums, index, i);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public List<List<Integer>> permute(int[] nums) {

        List<List<Integer>> ans = new ArrayList<>();
        solve(nums, ans, 0);
        return ans;
    }
}