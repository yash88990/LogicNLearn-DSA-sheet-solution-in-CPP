import java.util.*;

class Solution {
    public int threeSumClosest(int[] nums, int target) {

        int n = nums.length;

        if (n == 3)
            return nums[0] + nums[1] + nums[2];

        Arrays.sort(nums);

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // update closest sum
                if (Math.abs(sum - target) < Math.abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum < target) {
                    left++;
                } 
                else if (sum > target) {
                    right--;
                } 
                else {
                    return target; // exact match
                }
            }
        }

        return closestSum;
    }
}