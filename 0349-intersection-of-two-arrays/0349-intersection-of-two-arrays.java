import java.util.*;

class Solution {

    public int[] intersection(int[] nums1, int[] nums2) {

        // Sort both arrays
        Arrays.sort(nums1);
        Arrays.sort(nums2);

        int i = 0, j = 0;
        ArrayList<Integer> ans = new ArrayList<>();

        // Two pointer traversal
        while (i < nums1.length && j < nums2.length) {

            if (nums1[i] == nums2[j]) {

                // avoid duplicates
                if (ans.isEmpty() || ans.get(ans.size() - 1) != nums1[i]) {
                    ans.add(nums1[i]);
                }

                i++;
                j++;

            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        // Convert ArrayList to array
        int[] result = new int[ans.size()];
        for (int k = 0; k < ans.size(); k++) {
            result[k] = ans.get(k);
        }

        return result;
    }
}