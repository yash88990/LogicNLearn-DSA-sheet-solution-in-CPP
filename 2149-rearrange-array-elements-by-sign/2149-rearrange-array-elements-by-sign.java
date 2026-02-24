import java.util.*;

class Solution {
    public int[] rearrangeArray(int[] nums) {

        int n = nums.length;

        List<Integer> pos = new ArrayList<>();
        List<Integer> neg = new ArrayList<>();

        // Separate positive and negative numbers
        for (int num : nums) {
            if (num > 0)
                pos.add(num);
            else
                neg.add(num);
        }

        // Build answer array
        int[] ans = new int[n];
        int index = 0;

        for (int i = 0; i < pos.size(); i++) {
            ans[index++] = pos.get(i);
            ans[index++] = neg.get(i);
        }

        return ans;
    }
}