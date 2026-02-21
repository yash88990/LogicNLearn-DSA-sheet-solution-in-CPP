import java.util.*;

class Solution {
    public int[][] merge(int[][] intervals) {

        // sort intervals based on start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> ans = new ArrayList<>();

        // add first interval
        ans.add(intervals[0]);

        for (int i = 1; i < intervals.length; i++) {

            int[] lastInterval = ans.get(ans.size() - 1);

            // overlapping condition
            if (intervals[i][0] <= lastInterval[1]) {
                lastInterval[1] = Math.max(lastInterval[1], intervals[i][1]);
            } else {
                ans.add(intervals[i]);
            }
        }

        // convert List<int[]> → int[][]
        return ans.toArray(new int[ans.size()][]);
    }
}