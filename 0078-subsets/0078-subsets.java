import java.util.*;

class Solution {

    private void solve(int[] nums, List<Integer> output, int index, List<List<Integer>> ans) {
        // Base case
        if (index >= nums.length) {
            ans.add(new ArrayList<>(output)); // add copy of current subset
            return;
        }

        // Exclude current element
        solve(nums, output, index + 1, ans);

        // Include current element
        output.add(nums[index]);
        solve(nums, output, index + 1, ans);

        // Backtrack (remove last element)
        output.remove(output.size() - 1);
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> output = new ArrayList<>();

        solve(nums, output, 0, ans);
        return ans;
    }
}